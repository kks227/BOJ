#include <cstdio>
#include <cmath>
using namespace std;
const int MAX_N = 10000;
const int MAX_M = 100;
const int MAX = MAX_N * 26;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, M, K;
		char S[MAX_N+1];
		scanf("%d %d %d %s", &N, &M, &K, S);
		if(K == 1){
			for(int i = 0; i < M; ++i)
				putchar('a');
			puts("");
			continue;
		}

		int MOD = K;
		bool flag = false;
		for(int L = 1; !flag; ++L){
			int H = 0;
			bool used[MAX] = {false,};
			for(int i = 0; i < L-1; ++i)
				H = (H*K + S[i]-'a') % MOD;
			for(int i = L-1; i < N; ++i){
				H = (H*K + S[i]-'a') % MOD;
				used[H] = true;
			}
			for(int i = 0; i < MOD; ++i){
				if(!used[i]){
					char result[MAX_M+1] = {'\0',};
					H = i;
					for(int j = 0; j < L; ++j){
						result[L-j-1] = H % K + 'a';
						H /= K;
					}
					puts(result);
					flag = true;
					break;
				}
			}
			MOD *= K;
		}
	}
}