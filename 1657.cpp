#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, dp[14][14][16384], val[5][5] = {
	10, 8, 7, 5, 1,
	8, 6, 4, 3, 1,
	7, 4, 3, 2, 1,
	5, 3, 2, 2, 1,
	1, 1, 1, 1, 0
};
char c[14][14];

int tiling(int row, int col, int filled){
	if(row == N) return 0;
	if(col == M) return tiling(row+1, 0, filled);
	int &ret = dp[row][col][filled];
	if(ret != -1) return ret;
	if(filled & (1<<col))
		return ret = tiling(row, col+1, filled & ~(1<<col));

	ret = tiling(row, col+1, filled);
	if(row <= N-2)
		ret = max(ret, tiling(row, col+1, filled | (1<<col)) + val[c[row][col]][c[row+1][col]]);
	if(col <= M-2 && !(filled & (2<<col)))
		ret = max(ret, tiling(row, col+2, filled) + val[c[row][col]][c[row][col+1]]);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++){
			c[i][j] = getchar();
			if(c[i][j] == 'F') c[i][j] = 4;
			else c[i][j] -= 'A';
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tiling(0, 0, 0));
}