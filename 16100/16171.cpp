#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;
const int MAX = 101;

int main(){
	char S[MAX] = {'\0',}, K[MAX];
	int M, N;
	for(int i = 0; ; ++i){
		char c = getchar();
		if(c == '\n') break;
		if(isdigit(c)) --i;
		else S[i] = c;
	}
	scanf("%s", K);
	N = strlen(S);
	M = strlen(K);

	int p[MAX] = {0};
	for(int i = 1, j = 0; i < M; ++i){
		while(j > 0 && K[i] != K[j]) j = p[j-1];
		if(K[i] == K[j]) p[i] = ++j;
	}
	for(int i = 0, j = 0; i < N; ++i){
		while(j > 0 && S[i] != K[j]) j = p[j-1];
		if(S[i] == K[j]){
			if(j == M-1){
				puts("1");
				return 0;
			}
			else j++;
		}
	}
	puts("0");
}