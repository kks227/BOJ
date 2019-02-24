#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 10;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int R, C, sr, sc, er, ec, warp[MAX][MAX][4], d2w[MAX][MAX], dist[MAX][MAX];
		char map[MAX][MAX];
		memset(map, '#', sizeof(map));
		queue<int> Q;
		scanf("%d %d", &R, &C);
		for(int i = 1; i <= R; ++i){
			getchar();
			for(int j = 1; j <= C; ++j){
				map[i][j] = getchar();
				if(map[i][j] == 'O'){
					sr = i;
					sc = j;
				}
				else if(map[i][j] == 'X'){
					er = i;
					ec = j;
				}
			}
		}
		R += 2;
		C += 2;
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				dist[i][j] = INF;
				if(map[i][j] == '#'){
					d2w[i][j] = 0;
					Q.push(i*MAX + j);
				}
				else d2w[i][j] = INF;
			}
		}

		for(int i = 1; !Q.empty(); ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int r = Q.front() / MAX, c = Q.front() % MAX; Q.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
					if(d2w[nr][nc] == INF){
						d2w[nr][nc] = i;
						Q.push(nr*MAX + nc);
					}
				}
			}
		}

		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				if(map[i][j] == '#') continue;
				int k = j;
				for(; map[i][k+1] != '#'; ++k);
				for(int l = j; l <= k; ++l){
					warp[i][l][2] = i*MAX + j;
					warp[i][l][3] = i*MAX + k;
				}
				j = k;
			}
		}
		for(int j = 0; j < C; ++j){
			for(int i = 0; i < R; ++i){
				if(map[i][j] == '#') continue;
				int k = i;
				for(; map[k+1][j] != '#'; ++k);
				for(int l = i; l <= k; ++l){
					warp[l][j][0] = i*MAX + j;
					warp[l][j][1] = k*MAX + j;
				}
				i = k;
			}
		}

		bool visited[MAX][MAX] = {false,};
		priority_queue<P, vector<P>, greater<P>> PQ;
		PQ.push(P(0, sr*MAX + sc));
		dist[sr][sc] = 0;
		while(!PQ.empty()){
			int r, c;
			do{
				r = PQ.top().second / MAX;
				c = PQ.top().second % MAX;
				PQ.pop();
			}while(!PQ.empty() && visited[r][c]);
			if(visited[r][c]) break;
			visited[r][c] = true;

			for(int d = 0; d < 4; ++d){
				int nr = warp[r][c][d] / MAX, nc = warp[r][c][d] % MAX;
				if(dist[nr][nc] > dist[r][c] + d2w[r][c]){
					dist[nr][nc] = dist[r][c] + d2w[r][c];
					PQ.push(P(dist[nr][nc], nr*MAX + nc));
				}
				nr = r + roff[d];
				nc = c + coff[d];
				if(map[nr][nc] == '#') continue;
				if(dist[nr][nc] > dist[r][c] + 1){
					dist[nr][nc] = dist[r][c] + 1;
					PQ.push(P(dist[nr][nc], nr*MAX + nc));
				}
			}
		}

		printf("Case #%d: ", t);
		if(dist[er][ec] < INF) printf("%d\n", dist[er][ec]);
		else puts("THE CAKE IS A LIE");
	}
}