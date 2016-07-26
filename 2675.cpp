#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int T, R, len;
	char S[21];
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %s", &R, S);
		len = strlen(S);
		for(int i=0; i<len; i++)
			for(int j=0; j<R; j++)
				putchar(S[i]);
		puts("");
	}

	return 0;
}