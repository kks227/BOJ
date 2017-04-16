#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, dp[300][300];
bool mine[300][300];

int mining(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	ret = 0;
	if(r < R-1) ret = max(ret, mining(r+1, c));
	if(c < C-1) ret = max(ret, mining(r, c+1));
	return ret += mine[r][c];
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &mine[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", mining(0, 0));
}