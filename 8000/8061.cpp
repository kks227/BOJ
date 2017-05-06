#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX = 182;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int N, M, dist[MAX][MAX];
	bool B[MAX][MAX];
	priority_queue<P, vector<P>, greater<P>> PQ;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1d", &B[i][j]);
			dist[i][j] = B[i][j] ? 0 : INF;
			if(B[i][j]) PQ.push(P(0, i*MAX+j));
		}
	}

	bool visited[MAX][MAX] = {0};
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second/MAX;
			c = PQ.top().second%MAX;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(visited[r][c]) break;
		visited[r][c] = true;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
			if(dist[nr][nc] > dist[r][c] + 1){
				dist[nr][nc] = dist[r][c] + 1;
				PQ.push(P(dist[nr][nc], nr*MAX+nc));
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			printf("%d ", dist[i][j]);
		puts("");
	}
}