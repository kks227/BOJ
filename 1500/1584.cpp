#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M;
	char map[501][501] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int X1, Y1, X2, Y2;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		if(X1 > X2) swap(X1, X2);
		if(Y1 > Y2) swap(Y1, Y2);
		for(int i=Y1; i<=Y2; i++)
			for(int j=X1; j<=X2; j++)
				map[i][j] = 1;
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int X1, Y1, X2, Y2;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		if(X1 > X2) swap(X1, X2);
		if(Y1 > Y2) swap(Y1, Y2);
		for(int i=Y1; i<=Y2; i++)
			for(int j=X1; j<=X2; j++)
				map[i][j] = -1;
	}

	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push({0, 0});
	bool visited[501][501] = {0};
	int dist[501][501];
	for(int i=0; i<=500; i++)
		fill(dist[i], dist[i]+501, INF);
	dist[0][0] = 0;
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second/1000;
			c = PQ.top().second%1000;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(visited[r][c]) break;
		visited[r][c] = true;
		if(r == 500 && c == 500) break;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr > 500 || nc < 0 || nc > 500 || map[nr][nc] < 0 || visited[nr][nc]) continue;
			if(dist[nr][nc] > dist[r][c] + map[nr][nc]){
				dist[nr][nc] = dist[r][c] + map[nr][nc];
				PQ.push({dist[nr][nc], nr*1000+nc});
			}
		}
	}
	printf("%d\n", visited[500][500] ? dist[500][500] : -1);
}