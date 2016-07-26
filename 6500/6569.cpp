#include <cstdio>
#include <cstring>
using namespace std;

int N, M;
long long dp[11][11][2048];

long long tiling(int row, int col, int filled){
	if(row == N) return filled == 0;
	if(col == M) return tiling(row+1, 0, filled);
	long long &ret = dp[row][col][filled];
	if(ret != -1) return ret;
	if(filled & (1<<col))
		return ret = tiling(row, col+1, filled & ~(1<<col));

	ret = tiling(row, col+1, filled | (1<<col));
	if(col <= M-2 && !(filled & (2<<col))) ret += tiling(row, col+2, filled);
	return ret;
}

int main(){
	while(1){
		scanf("%d %d", &N, &M);
		if(N==0 && M==0) break;
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", N*M%2 ? 0 : tiling(0, 0, 0));
	}
}