#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, map[MAX][MAX], dist[MAX][MAX];
	queue<int> Q;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2){
				Q.push(i*MAX + j);
				dist[i][j] = 0;
			}
			else dist[i][j] = INF;
		}
	}

	for(int i = 1; !Q.empty(); ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 0) continue;
				if(dist[nr][nc] == INF){
					dist[nr][nc] = i;
					Q.push(nr*MAX + nc);
				}
			}
		}
	}

	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j] == 0) printf("0 ");
			else if(dist[i][j] < INF) printf("%d ", dist[i][j]);
			else printf("-1 ");
		}
		puts("");
	}
}