#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, map[MAX][MAX], dist[3][MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%1d", &map[i][j]);
			for(int k = 0; k < 3; ++k)
				dist[k][i][j] = INF;
		}
	}
	for(int i = 0; i < 3; ++i){
		int sr, sc;
		scanf("%d %d", &sr, &sc);
		queue<int> Q;
		bool visited[MAX][MAX] = {false,};
		visited[--sr][--sc] = true;
		Q.push(sr*MAX + sc);
		for(int d = 0; !Q.empty(); ++d){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int r = Q.front()/MAX, c = Q.front()%MAX;
				Q.pop();
				dist[i][r][c] = d;
				for(int k = 0; k < 4; ++k){
					int nr = r+roff[k], nc = c+coff[k];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc]) continue;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*MAX + nc);
					}
				}
			}
		}
	}

	int res1 = INF+1, res2 = 0;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j]) continue;
			int temp = 0;
			for(int k = 0; k < 3; ++k)
				temp = max(dist[k][i][j], temp);
			if(temp < res1){
				res1 = temp;
				res2 = 1;
			}
			else if(temp == res1) ++res2;
		}
	}
	if(res1 == INF) puts("-1");
	else printf("%d\n%d\n", res1, res2);
}