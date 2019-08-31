#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
using namespace std;
const int MAX_K = 5;
const int MAX = 50;
const int MAX_P = 10001;
const char dc[4] = {'U', 'R', 'D', 'L'};
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
typedef pair<int, int> P;

class Bacterium{
public:
	Bacterium(){
		bool notPrime[MAX_P] = {true, true,};
		prime.push_back(2);
		for(int i = 3; i < MAX_P; i += 2){
			if(notPrime[i]) continue;
			prime.push_back(i);
			for(int j = i*i; j < MAX_P; j += i*2)
				notPrime[j] = true;
		}
	}

	void input(){
		scanf("%d %d %d %d %d", &R, &C, &K, &tr, &tc);
		--tr; --tc;
		for(int k = 0; k < K; ++k){
			char sdc;
			scanf("%d %d %c", r+k, c+k, &sdc);
			--r[k]; --c[k];
			for(int i = 0; i < 4; ++i)
				if(sdc == dc[i]) d[k] = i;
			for(int i = 0; i < R; ++i)
				for(int j = 0; j < C; ++j)
					scanf("%1d", &X[k][i][j]);
			lSize[k] = -1;
		}
	}

	long long preprocess(){
		memset(t, -1, sizeof(t));
		for(int i = 0; i < R*C*4; ++i){
			bool flag = true;
			for(int k = 0; k < K; ++k)
				if(r[k] != tr || c[k] != tc) flag = false;
			if(flag) return i + 1LL;

			for(int k = 0; k < K; ++k){
				int &cr = r[k], &cc = c[k], &cd = d[k];
				cd = (cd + X[k][cr][cc]) % 4;
				int nr = cr + roff[cd], nc = cc + coff[cd];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C){
					cd = (cd + 2) % 4;
					nr = cr + roff[cd];
					nc = cc + coff[cd];
				}

				if(t[k][cr][cc][cd] != -1){
					if(lSize[k] == -1) lSize[k] = i - t[k][cr][cc][cd];
				}
				else t[k][cr][cc][cd] = i;
				cr = nr;
				cc = nc;
			}
		}
		return -1;
	}

	long long solve(){
		for(int k = 0; k < K; ++k){
			for(int i = 0; i < lSize[k]; ++i){
				int &cr = r[k], &cc = c[k], &cd = d[k];
				if(cr == tr && cc == tc) lTrap[k].push_back(i);
				cd = (cd + X[k][cr][cc]) % 4;
				int nr = cr + roff[cd], nc = cc + coff[cd];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C){
					cd = (cd + 2) % 4;
					nr = cr + roff[cd];
					nc = cc + coff[cd];
				}
				cr = nr;
				cc = nc;
			}

			if(lTrap[k].empty()) return -1;
			mVal[k] = lSize[k];
		}

		result = -1;
		backtrack();
		return result;
	}

private:
	int R, C, K, tr, tc, lSize[MAX_K];
	int r[MAX_K], c[MAX_K], d[MAX_K], X[MAX_K][MAX][MAX];
	int t[MAX_K][MAX][MAX][4], mVal[MAX_K], rVal[MAX_K];
	long long result;
	vector<int> prime, lTrap[MAX_K];

	void backtrack(int k = 0){
		if(k == K){
			long long temp = solveCongeranceSystem();
			if(temp != -1 && (result == -1 || result > temp)) result = temp;
			return;
		}
		for(int i: lTrap[k]){
			rVal[k] = i;
			backtrack(k+1);
		}
	}

	long long solveCongeranceSystem(){
		map<int, P> cong;
		for(int k = 0; k < K; ++k){
			int m = mVal[k], a = rVal[k]; // notice: mVal, rVal < MAX_P
			for(int j = 0; m > 1; ++j){
				int p = prime[j], q = 1;
				if(m % p != 0) continue;
				while(m % p == 0){
					m /= p;
					q *= p;
				}

				int b = a % q;
				if(cong.find(p) != cong.end()){
					int q1 = q, q2 = cong[p].first, b1 = b, b2 = cong[p].second;
					if(q1 > q2){
						swap(q1, q2);
						swap(b1, b2);
					}
					if(b2 % q1 != b1) return -1;
					else cong[p] = P(q2, b2);
				}
				else cong[p] = P(q, b);
			}
		}

		long long M = 1, x = 0;
		for(auto &c: cong) M *= c.second.first;
		for(auto &c: cong){
			int m = c.second.first, a = c.second.second;
			long long n = M / m, s = inv(n, m);
			if(s == -1) return -1;
			x = (x + mtp(n, s*a, M)) % M;
		}
		return R*C*4 + x + 1;
	}

	inline long long mod(long long a, long long m){
		if(a >= 0) return a % m;
		return (a + (-a/m+1)*m) % m;
	}

	inline long long inv(long long a, long long m){
		long long r1 = m, r2 = a, t1 = 0, t2 = 1;
		while(r2 > 0){
			long long q = r1/r2, r = r1 - q*r2, t = t1 - q*t2;
			r1 = r2; r2 = r;
			t1 = t2; t2 = t;
		}
		return r1 == 1 ? mod(t1, m) : -1;
	}

	long long mtp(long long a, int b, long long m){
		long long c = 0, d = 0;
		int k = sqrt(b);
		for(int i = 0; i < k; ++i)
			d = (d + a) % m;
		for(int i = 0; i < k; ++i)
			c = (c + d) % m;
		for(int i = k*k; i < b; ++i)
			c = (c + a) % m;
		return c;
	}
};



int main(){
	Bacterium solver;
	solver.input();
	long long result = solver.preprocess();
	if(result == -1) result = solver.solve();
	printf("%lld\n", result);
}