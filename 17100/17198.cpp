#include <cstdio>
#include <queue>
#include <algorithm>
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int N = 10;
const int INF = 1e9;
using namespace std;

int main(){
	int dist[N][N], sr, sc, er, ec;
	char map[N][N];
	for(int i = 0; i < N; ++i){
		fill(dist[i], dist[i] + N, INF);
		for(int j = 0; j < N; ++j){
			map[i][j] = getchar();
			if(map[i][j] == 'L'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == 'B'){
				er = i;
				ec = j;
			}
		}
		getchar();
	}

	queue<int> Q;
	Q.push(sr*N + sc);
	dist[sr][sc] = 0;
	while(!Q.empty()){
		int r = Q.front() / N, c = Q.front() % N;
		Q.pop();
		for(int d = 0; d < 4; ++d){
			int nr = r + roff[d], nc = c + coff[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 'R') continue;
			if(dist[nr][nc] == INF){
				dist[nr][nc] = dist[r][c] + 1;
				Q.push(nr*N + nc);
			}
		}
	}
	printf("%d\n", dist[er][ec]-1);
}