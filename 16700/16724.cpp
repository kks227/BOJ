#include <cstdio>
#include <unordered_map>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int R, C, dfsn[1000][1000], dcnt;
char map[1000][1000];
unordered_map<char, int> C2D;

bool dfs(int r, int c, int k){
	dfsn[r][c] = k;
	int d = C2D[map[r][c]], nr = r+roff[d], nc = c+coff[d];
	if(dfsn[nr][nc] == k) return true;
	if(dfsn[nr][nc] >= 0) return false;
	return dfs(nr, nc, k);
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			dfsn[i][j] = -1;
		}
	}
	int result = 0;
	C2D['U'] = 0;
	C2D['D'] = 1;
	C2D['L'] = 2;
	C2D['R'] = 3;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			if(dfsn[i][j] == -1 && dfs(i, j, dcnt++)) ++result;
	printf("%d\n", result);
}