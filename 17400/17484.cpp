#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 6;
const int INF = 1e9;

int R, C, A[MAX][MAX], dp[MAX][MAX][3];

int moon(int r, int c, int k){
	int &ret = dp[r][c][k];
	if(ret != -1) return ret;
	if(r == R-1) return ret = A[r][c];
	ret = INF;
	--k;
	for(int d = -1; d <= 1; ++d)
		if(d != k && 0 <= c+d && c+d < C) ret = min(moon(r+1, c+d, d+1), ret);
	return ret += A[r][c];
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &A[i][j]);
	memset(dp, -1, sizeof(dp));
	int result = INF;
	for(int i = 0; i < C; ++i)
		for(int j = 0; j < 3; ++j)
			result = min(moon(0, i, j), result);
	printf("%d\n", result);
}