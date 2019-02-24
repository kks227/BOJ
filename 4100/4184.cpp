#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000;
const int roff[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int coff[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
	int R, C, Q, map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%1d", &map[i][j]);

	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int sr, sc, er, ec, dist[MAX][MAX];
		scanf("%d %d %d %d", &sr, &sc, &er, &ec);
		--sr; --sc; --er; --ec;

		bool visited[MAX][MAX] = {false,};
		queue<int> Q;
		while(sr >= 0 && sr < R && sc >= 0 && sc < C && !visited[sr][sc]){
			visited[sr][sc] = true;
			dist[sr][sc] = 0;
			Q.push(sr*MAX + sc);
			int r = sr, c = sc;
			sr = r + roff[map[r][c]];
			sc = c + coff[map[r][c]];
		}

		for(int k = 1; !Q.empty(); ++k){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
				for(int d = 0; d < 8; ++d){
					int nr = r + roff[d], nc = c + coff[d];
					while(nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]){
						visited[nr][nc] = true;
						dist[nr][nc] = k;
						Q.push(nr*MAX + nc);
						int r = nr, c = nc;
						nr = r + roff[map[r][c]];
						nc = c + coff[map[r][c]];
					}
				}
			}
		}

		printf("%d\n", dist[er][ec]);
	}
}