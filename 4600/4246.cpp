#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		char S[201];
		scanf("%s", S);
		int L = strlen(S);
		for(int i=0; i<L/N; i++)
			if(i%2) reverse(S+i*N, S+(i+1)*N);
		for(int i=0; i<N; i++)
			for(int j=0; j<L/N; j++)
				putchar(S[j*N+i]);
		puts("");
	}
}