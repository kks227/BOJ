#include <cstdio>
using namespace std;

int main(){

	int M, N, U, L, R, D;
	scanf("%d %d %d %d %d %d", &M, &N, &U, &L, &R, &D);
	char crossword[10][11];
	for(int i=0; i<M; i++)
		scanf("%s", crossword[i]);
	for(int i=0; i<M+U+D; i++){
		for(int j=0; j<N+L+R; j++)
			putchar((i>=U && i<M+U && j>=L && j<N+L)?crossword[i-U][j-L]:((i+j)%2?'.':'#'));
		putchar('\n');
	}

	return 0;
}