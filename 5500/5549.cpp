#include <cstdio>
using namespace std;

int main(){
	int R, C, K, S[3][1001][1001] = {0};
	scanf("%d %d %d", &R, &C, &K);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			char c = getchar();
			int l = 0;
			if(c == 'O') l = 1;
			else if(c == 'I') l = 2;
			for(int k=0; k<3; k++)
				S[k][i+1][j+1] = S[k][i+1][j] + S[k][i][j+1] - S[k][i][j];
			S[l][i+1][j+1]++;
		}
	}
	for(int i=0; i<K; i++){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--; c1--;
		for(int j=0; j<3; j++)
			printf("%d ", S[j][r2][c2] - S[j][r1][c2] - S[j][r2][c1] + S[j][r1][c1]);
		puts("");
	}
}