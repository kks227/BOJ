#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int coff[] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int MAX = 500;

int main(){
	int N, M, sr, sc, dist[MAX][MAX];
	scanf("%d %d %d %d", &N, &M, &sr, &sc);
	for(int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + N, -1);
	dist[--sr][--sc] = 0;
	queue<int> Q;
	Q.push(sr*MAX + sc);
	while(!Q.empty()){
		int r = Q.front() / MAX, c = Q.front() % MAX;
		Q.pop();
		for(int d = 0; d < 8; ++d){
			int nr = r + roff[d], nc = c + coff[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(dist[nr][nc] == -1){
				dist[nr][nc] = dist[r][c] + 1;
				Q.push(nr*MAX + nc);
			}
		}
	}
	for(int i = 0; i < M; ++i){
		int r, c;
		scanf("%d %d", &r, &c);
		printf("%d ", dist[r-1][c-1]);
	}
}