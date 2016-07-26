#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char S[1000001];
		scanf("%s", S);
		if(S[0] == '.') break;
		int N = strlen(S);

		int pi[1000000] = {0}, j = 0;
		for(int i=1; i<N; i++){
			while(j > 0 && S[i] != S[j]) j = pi[j-1];
			if(S[i] == S[j]) pi[i] = ++j;
		}
		int q = pi[N-1], r = N-q;
		if(q==0 || q%r!=0) puts("1");
		else printf("%d\n", q/r+1);
	}
}