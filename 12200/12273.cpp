#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int R, C, map[MAX][MAX], dist[MAX][MAX], result[MAX][MAX] = {0,}, sr, sc, er, ec;
		scanf("%d %d %d %d %d %d", &R, &C, &sr, &sc, &er, &ec);
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				scanf("%d", &map[i][j]);
				dist[i][j] = INF;
			}
		}

		queue<int> Q;
		Q.push(sr*MAX + sc);
		dist[sr][sc] = 0;
		result[sr][sc] = map[sr][sc];
		for(int i = 1; !Q.empty(); ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] < 0) continue;
					if(dist[nr][nc] == INF){
						dist[nr][nc] = i;
						result[nr][nc] = result[r][c] + map[nr][nc];
						Q.push(nr*MAX + nc);
					}
					else if(dist[nr][nc] == dist[r][c] + 1)
						result[nr][nc] = max(result[r][c] + map[nr][nc], result[nr][nc]);
				}
			}
		}

		printf("Case #%d: ", t);
		if(dist[er][ec] == INF) puts("Mission Impossible.");
		else printf("%d\n", result[er][ec]);
	}
}