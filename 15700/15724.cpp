#include <cstdio>
using namespace std;

int main(){
	int R, C, K, A[1024][1024], rSum[1025][1025] = {0};
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &A[i][j]);
			rSum[i+1][j+1] = rSum[i][j+1] + rSum[i+1][j] - rSum[i][j] + A[i][j];
		}
	}
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		c1--; r1--;
		printf("%d\n", rSum[r2][c2] - rSum[r2][c1] - rSum[r1][c2] + rSum[r1][c1]);
	}
}