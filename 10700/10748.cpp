#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int R, C, K, map[100][100], dp[100][100];

int hopscotch(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	if(r == 0 && c == 0) return ret = 1;

	ret = 0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(map[i][j] != map[r][c]) ret = (ret + hopscotch(i, j)) % MOD;
	return ret;
}

int main(){
	scanf("%d %d %d", &R, &C, &K);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", hopscotch(R-1, C-1));
}