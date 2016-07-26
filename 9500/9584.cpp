#include <cstdio>
using namespace std;

int main(){
	char code[10], S[1000][10];
	int N, result = 0;
	bool match[1000] = {0};
	scanf("%s %d", code, &N);
	for(int i=0; i<N; i++){
		scanf("%s", S[i]);
		match[i] = true;
		for(int j=0; j<9; j++)
			if(code[j]!='*' && code[j]!=S[i][j]){
				match[i] = false;
				break;
			}
		if(match[i]) result++;
	}
	printf("%d\n", result);
	for(int i=0; i<N; i++)
		if(match[i]) puts(S[i]);
}