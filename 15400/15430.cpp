#include <cstdio>
using namespace std;
const int MAX = 81;
const int MOD = 27;

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char o, S[MAX] = {0,};
		scanf(" %c", &o);
		getchar();
		int L = 0;
		while(1){
			S[L] = getchar();
			if(S[L] == '\n'){
				S[L] = '\0';
				break;
			}
			++L;
		}

		if(o == 'e'){
			int pSum = 0;
			for(int i = 0; i < L; ++i){
				int k = (S[i] == ' ' ? 0 : S[i] - 'a' + 1);
				pSum += k;
				k = pSum % MOD;
				putchar(k == 0 ? ' ' : k - 1 + 'a');
			}
		}
		else{
			int pSum[MAX] = {0,}, kPrev = 0;
			for(int i = 0; i < L; ++i){
				int k = (S[i] == ' ' ? 0 : S[i] - 'a' + 1);
				pSum[i] = k - kPrev;
				if(i > 0) pSum[i] += pSum[i-1];
				if(k < kPrev) pSum[i] += MOD;
				kPrev = k;
			}
			for(int i = 0; i < L; ++i){
				int k = pSum[i] - (i > 0 ? pSum[i-1] : 0);
				putchar(k == 0 ? ' ' : k - 1 + 'a');
			}
		}
		puts("");
	}
}