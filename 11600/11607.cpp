#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
	int R, C, map[500][500], dist[500][500];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			scanf("%1d", &map[i][j]);
		fill(dist[i], dist[i]+C, INF);
	}

	dist[0][0] = 0;
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int r = Q.front()/500, c = Q.front()%500;
		Q.pop();
		for(int d=0; d<4; d++){
			int nr = r+roff[d]*map[r][c], nc = c+coff[d]*map[r][c];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(dist[nr][nc] == INF){
				dist[nr][nc] = dist[r][c] + 1;
				Q.push(nr*500 + nc);
			}
		}
	}
	if(dist[R-1][C-1] < INF) printf("%d\n", dist[R-1][C-1]);
	else puts("IMPOSSIBLE");
}