#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_P = 40000;
const int MOD = 1e9;

int main(){
	bool np[MAX_P] = {true, true,};
	vector<int> prime(1, 2);
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j < MAX_P; j += i*2)
			np[j] = true;
	}
	unordered_map<int, int> M[2];
	for(int i = 0; i < 2; ++i){
		int N;
		scanf("%d", &N);
		for(int j = 0; j < N; ++j){
			int k;
			scanf("%d", &k);
			for(int p: prime){
				if(k == 1) break;
				if(k%p == 0){
					int cnt = 0;
					while(k%p == 0){
						++cnt;
						k /= p;
					}
					if(M[i].find(p) == M[i].end()) M[i][p] = cnt;
					else M[i][p] += cnt;
				}
			}
			if(k > 1){
				if(M[i].find(k) == M[i].end()) M[i][k] = 1;
				else ++M[i][k];
			}
		}
	}
	bool large = false;
	int result = 1;
	for(auto &p: M[0]){
		int q = p.first, r1 = p.second;
		int r2 = (M[1].find(q) == M[1].end() ? 0 : M[1][q]);
		int r = min(r1, r2);
		for(int i = 0; i < r; ++i){
			long long temp = 1LL*result*q;
			if(temp >= MOD) large = true;
			result = temp % MOD;
		}
	}
	printf((large ? "%09d" : "%d"), result);
}