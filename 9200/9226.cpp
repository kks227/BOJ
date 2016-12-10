#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char S[43] = {0};
		scanf("%s", S);
		if(S[0] == '#') break;

		int i = 0, N = strlen(S);
		for(; i<N && S[i]!='a' && S[i]!='e' && S[i]!='i' && S[i]!='o' && S[i]!='u'; i++) S[N+i] = S[i];
		S[N+i] = 'a';
		S[N+i+1] = 'y';
		puts(S+i);
	}
}