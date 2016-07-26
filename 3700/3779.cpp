#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		char S[1000001];
		scanf("%s", S);
		int pi[1000000] = {0}, j = 0;
		for(int i=1; i<N; i++){
			while(j > 0 && S[i] != S[j]) j = pi[j-1];
			if(S[i] == S[j]) pi[i] = ++j;
		}
		printf("Test case #%d\n", t);
		for(int i=1; i<N; i++){
			int q = pi[i], r = i+1-q;
			if(q>0 && q%r==0) printf("%d %d\n", i+1, q/r+1);
		}
		puts("");
	}
}