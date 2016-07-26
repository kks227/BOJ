#include <cstdio>
using namespace std;

int main(){
	int R, C, A, B;
	char card[100][101] = {0};
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			card[i][j] = card[i][2*C-j-1] = card[2*R-i-1][j] = card[2*R-i-1][2*C-j-1] = getchar();
	}
	scanf("%d %d", &A, &B);
	A--; B--;
	card[A][B] = (card[A][B]=='#' ? '.' : '#');
	for(int i=0; i<R*2; i++)
		puts(card[i]);
}