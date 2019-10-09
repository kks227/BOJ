#include <cstdio>
using namespace std;
const int MAX = 5;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int R, C, K;
bool visited[MAX][MAX];
char map[MAX][MAX];

int dfs(int r, int c, int k){
	if(map[r][c] == 'T') return 0;
	if(r == 0 && c == C-1) return !k;
	if(k == 0) return 0;

	int result = 0;
	visited[r][c] = true;
	for(int d = 0; d < 4; ++d){
		int nr = r+roff[d], nc = c+coff[d];
		if(nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) result += dfs(nr, nc, k-1);
	}
	visited[r][c] = false;
	return result;
}

int main(){
	scanf("%d %d %d", &R, &C, &K);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}
	printf("%d\n", dfs(R-1, 0, K-1));
}