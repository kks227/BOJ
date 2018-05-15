#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int N, M, H[102][102] = {0};
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d", &H[i][j]);
	N += 2; M += 2;

	int dist[102][102];
	for(int i=0; i<N; i++)
		fill(dist[i], dist[i]+M, INF);
	dist[0][0] = 0;
	bool visited[102][102] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second/1000;
			c = PQ.top().second%1000;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(visited[r][c]) break;
		visited[r][c] = true;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
			int nd = max(dist[r][c], H[nr][nc]);
			if(dist[nr][nc] > nd){
				dist[nr][nc] = nd;
				PQ.push(P(nd, nr*1000+nc));
			}
		}
	}

	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			result += dist[i][j] - H[i][j];
	printf("%d\n", result);
}