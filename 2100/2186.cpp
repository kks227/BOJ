#include <cstdio>
#include <cstring>
using namespace std;
const int roff[4] = {0, -1, 0, 1};
const int coff[4] = {-1, 0, 1, 0};

int R, C, K, dp[100][100][81];
char map[100][100], W[81];

int cnt(int r, int c, int pos){
	int &ret = dp[r][c][pos];
	if(ret != -1) return ret;
	if(!W[pos]) return ret = 1;

	ret = 0;
	for(int d=0; d<4; d++){
		for(int k=1; k<=K; k++){
			int nr = r+roff[d]*k, nc = c+coff[d]*k;
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(map[nr][nc] == W[pos]) ret += cnt(nr, nc, pos+1);
		}
	}
	return ret;
}

int main(){
	scanf("%d %d %d", &R, &C, &K);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}
	scanf("%s", W);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(map[i][j] == W[0]) result += cnt(i, j, 1);
	printf("%d\n", result);
}