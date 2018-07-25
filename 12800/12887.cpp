#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = -1e9;

int M, dp[51][4];
char map[2][50];

int path(int r, int status){
	int &ret = dp[r][status];
	if(ret != -1) return ret;
	if(status == 3) return ret = IMPOSSIBLE;
	if(status == 1 && map[1][r] == '#') return ret = IMPOSSIBLE;
	if(status == 2 && map[0][r] == '#') return ret = IMPOSSIBLE;
	if(r == M) return ret = 0;

	int flag = (map[1][r] == '#')*2 + (map[0][r] == '#');
	ret = path(r+1, flag);
	if(status != 2) ret = max(path(r+1, 1 | flag) + (map[0][r] == '.'), ret);
	if(status != 1) ret = max(path(r+1, 2 | flag) + (map[1][r] == '.'), ret);
	return ret;
}

int main(){
	scanf("%d", &M);
	for(int i=0; i<2; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", path(0, 0));
}