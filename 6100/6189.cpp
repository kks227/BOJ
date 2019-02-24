#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 100;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
	int R, C, sr, sc, er, ec, dist[MAX][MAX];
	scanf("%d %d\n", &R, &C);
	char map[MAX][MAX];
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == 'B'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == 'C'){
				er = i;
				ec = j;
			}
			dist[i][j] = INF;
		}
		getchar();
	}

	queue<int> Q;
	Q.push(sr*MAX + sc);
	for(int i = 0; !Q.empty(); ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
			dist[r][c] = i;
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '*') continue;
				if(dist[nr][nc] == INF){
					dist[nr][nc] = i;
					Q.push(nr*MAX + nc);
				}
			}
		}
	}
	printf("%d\n", dist[er][ec]);
}