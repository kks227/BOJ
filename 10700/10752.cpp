#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 15;

int R, C, dp[MAX][MAX];
char map[MAX][MAX];

int hopscotch(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	if(r == 0 && c == 0) return ret = 1;

	ret = 0;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			if(map[i][j] != map[r][c]) ret += hopscotch(i, j);
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", hopscotch(R-1, C-1));
}