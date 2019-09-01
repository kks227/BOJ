#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX = 1000;

int main(){
	int N, K, S[MAX_N-1][MAX*2+1], T[MAX], Slen[MAX_N-1], Tlen, p[MAX] = {0,};
	scanf("%d %d %d", &N, &K, &Tlen);
	for(int i = 0; i < Tlen; ++i)
		scanf("%d", T+i);
	for(int i = 0; i < N-1; ++i){
		scanf("%d", Slen+i);
		S[i][Slen[i]] = -1;
		for(int j = 0; j < Slen[i]; ++j){
			scanf("%d", &S[i][j]);
			S[i][2*Slen[i]-j] = S[i][j];
		}
		Slen[i] = Slen[i]*2 + 1;
	}

	for(int k = 0; k <= Tlen-K; ++k){
		int U[MAX];
		copy(T+k, T+K+k, U);
		for(int i = 1, j = 0; i < K; ++i){
			while(j > 0 && U[i] != U[j]) j = p[j-1];
			if(U[i] == U[j]) p[i] = ++j;
		}

		bool flag = true;
		for(int l = 0; l < N-1 && flag; ++l){
			flag = false;
			for(int i = 0, j = 0; i < Slen[l]; ++i){
				while(j > 0 && S[l][i] != U[j]) j = p[j-1];
				if(S[l][i] == U[j]){
					if(j == K-1){
						flag = true;
						break;
					}
					++j;
				}
			}
		}
		if(flag){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}