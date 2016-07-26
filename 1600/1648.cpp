#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 9901;

int N, M, dp[14][14][16384];

int tiling(int row, int col, int filled){
	if(row == N) return filled == 0;
	if(col == M) return tiling(row+1, 0, filled);
	int &ret = dp[row][col][filled];
	if(ret != -1) return ret;
	if(filled & (1<<col))
		return ret = tiling(row, col+1, filled & ~(1<<col));
	
	ret = tiling(row, col+1, filled | (1<<col));
	if(col <= M-2 && !(filled & (2<<col))) ret += tiling(row, col+2, filled);
	return ret %= MOD;
}

int main(){
	scanf("%d %d", &N, &M);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", N*M%2 ? 0 : tiling(0, 0, 0));
}