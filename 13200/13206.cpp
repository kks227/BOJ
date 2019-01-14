#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_P = 1001;
const int MOD = 1000000007;

int main(){
	bool np[MAX_P] = {false,};
	vector<int> prime(1, 2);
	for(int i = 3; i < MAX_P; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j < MAX_P; j += i*2)
			np[j] = true;
	}
	int P = prime.size();

	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, result = 1;
		vector<int> cnt(P, 0), factor(P, 1);
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			int A;
			scanf("%d", &A);
			for(int j = 0; j < P && A > 1; ++j){
				int tcnt = 0, temp = 1;
				while(A%prime[j] == 0){
					++tcnt;
					temp = 1LL * temp * prime[j] % MOD;
					A /= prime[j];
				}
				if(cnt[j] < tcnt){
					cnt[j] = tcnt;
					factor[j] = temp;
				}
			}
		}
		for(int i = 0; i < P; ++i)
			result = 1LL * result * factor[i] % MOD;
		printf("%d\n", result);
	}
}