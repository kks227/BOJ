#include <cstdio>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int R, C;
bool map[250][250], visited[250][250];

void dfs(int r, int c){
	visited[r][c] = true;
	for(int d=0; d<8; d++){
		int nr = r+roff[d], nc = c+coff[d];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if(map[nr][nc] && !visited[nr][nc]) dfs(nr, nc);
	}
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	int result = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] && !visited[i][j]){
				result++;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", result);
}