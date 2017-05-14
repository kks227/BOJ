#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const long long INF = 1e18;
typedef pair<long long, int> P;

int main(){
	int N, T, D[100][100];
	long long dist[100][100][3];
	scanf("%d %d", &N, &T);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &D[i][j]);
			for(int k=0; k<3; k++)
				dist[i][j][k] = INF;
		}
	}

	bool visited[100][100][3] = {0};
	dist[0][0][0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int r, c, k;
		do{
			c = PQ.top().second % 100;
			r = PQ.top().second % 10000 / 100;
			k = PQ.top().second / 10000;
			PQ.pop();
		}while(visited[r][c][k] && !PQ.empty());
		if(visited[r][c][k]) break;
		visited[r][c][k] = true;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			int nd = dist[r][c][k] + T, nk = (k+1)%3;
			if(k == 2) nd += D[nr][nc];
			if(dist[nr][nc][nk] > nd){
				dist[nr][nc][nk] = nd;
				PQ.push(P(nd, nk*10000 + nr*100 + nc));
			}
		}
	}

	long long result = INF;
	for(int i=0; i<3; i++)
		result = min(result, dist[N-1][N-1][i]);
	printf("%lld\n", result);
}