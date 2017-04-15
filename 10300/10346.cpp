#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};

int R, C, cnt;
bool adj[50][50][4], visited[50][50], cyclic;

void dfs(int r, int c, int pr, int pc){
	visited[r][c] = true;
	cnt++;
	for(int d=0; d<4; d++){
		if(!adj[r][c][d]) continue;
		int nr = r+roff[d], nc = c+coff[d];
		if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
		if(!visited[nr][nc]) dfs(nr, nc, r, c);
		else if(pr != -1 && (nr != pr || nc != pc)) cyclic = true;
	}
}



int main(){
	while(1){
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		memset(adj, 0, sizeof(adj));
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				char c = getchar();
				int k = c - (c>'9' ? 'A'-10 : '0');
				for(int d=0; d<4; d++)
					adj[i][j][d] = !(k & 1<<3-d);
			}
		}
		int r[2], c[2];
		cnt = 0;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				for(int d=0; d<4; d++){
					if(!adj[i][j][d]) continue;
					int ni = i+roff[d], nj = j+coff[d];
					if(ni < 0 || ni >= R || nj < 0 || nj >= C){
						r[cnt] = i;
						c[cnt] = j;
						cnt++;
					}
				}
			}
		}
		assert(cnt == 2);

		cnt = 0;
		cyclic = false;
		memset(visited, 0, sizeof(visited));
		dfs(r[0], c[0], -1, -1);
		if(!visited[r[1]][c[1]]) puts("NO SOLUTION");
		else if(cnt < R*C) puts("UNREACHABLE CELL");
		else if(cyclic) puts("MULTIPLE PATHS");
		else puts("MAZE OK");
	}
}