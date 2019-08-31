#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;
const int MAX_P = 40001;
typedef pair<int, int> P;

inline int mod(int n, int a){
	if(a >= 0) return a % n;
	return (a + (-a/n+1)*n) % n;
}

inline int inv(int a, int m){
	int r1 = m, r2 = a, t1 = 0, t2 = 1;
	while(r2 > 0){
		int q = r1/r2, r = r1 - q*r2, t = t1 - q*t2;
		r1 = r2; r2 = r;
		t1 = t2; t2 = t;
	}
	return r1 == 1 ? mod(m, t1) : -1;
}



int main(){
	bool notPrime[MAX_P] = {true, true,};
	vector<int> prime(1, 2);
	for(int i = 3; i < MAX_P; i += 2){
		if(notPrime[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j < MAX_P; j += i*2)
			notPrime[j] = true;
	}

	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int mod[2], val[2];
		scanf("%d %d %d %d", mod, mod+1, val, val+1);

		map<int, P> cong;
		bool impossible = false;
		for(int i = 0; i < 2; ++i){
			int m = mod[i], a = val[i] - 1;
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
					if(b2 % q1 != b1) impossible = true;
					else cong[p] = P(q2, b2);
				}
				else cong[p] = P(q, b);
			}
		}

		int M = 1, x = 0;
		if(!impossible){
			for(auto &c: cong) M *= c.second.first;
			for(auto &c: cong){
				int m = c.second.first, a = c.second.second, n = M / m, s = inv(n, m);
				if(s == -1){
					impossible = true;
					break;
				}
				x = (x + 1LL*n*s*a) % M;
			}
		}
		if(impossible) puts("-1");
		else printf("%d\n", x + 1);
	}
}