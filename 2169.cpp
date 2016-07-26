#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = -1000000000;

int N, M, val[1000][1000], dp[1000][1000][2];

int maxSum(int r, int c, bool rightward){
	int &ret = dp[r][c][rightward];
	if(ret != -1) return ret;
	if(r==N-1 && c==M-1) return ret = val[r][c];
	if(r==N-1 && !rightward) return ret = IMPOSSIBLE;

	ret = IMPOSSIBLE;
	if(r < N-1) ret = max(maxSum(r+1, c, false), maxSum(r+1, c, true));
	if(!rightward && c>0) ret = max(ret, maxSum(r, c-1, false));
	if(rightward && c<M-1) ret = max(ret, maxSum(r, c+1, true));
	if(ret != IMPOSSIBLE) ret += val[r][c];
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &val[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxSum(0, 0, true));
}