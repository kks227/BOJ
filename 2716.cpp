#include <cstdio>
using namespace std;

int main(){

	int N, len, level, maxlevel, result;
	char S[151], c;
	scanf("%d", &N);
	getchar();
	for(int i=0; i<N; i++){
		len = 0;
		while((c=getchar()) != '\n'){
			S[len++] = c;
		}
		level = maxlevel = 0;
		for(int j=0; j<len; j++){
			if(S[j] == '['){
				level++;
				if(level > maxlevel) maxlevel = level;
			}
			else level--;
		}
		result = 1;
		for(int j=0; j<maxlevel; j++)
			result *= 2;
		printf("%d\n", result);
	}

	return 0;
}