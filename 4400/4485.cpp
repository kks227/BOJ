#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1000000000;
typedef pair<int, int> P;

int main(){
	for(int t=1; ; t++){
		int N, map[125][125], dist[125][125];
		scanf("%d", &N);
		if(N == 0) break;

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d", &map[i][j]);
				dist[i][j] = INF;
			}
		}
		bool visited[125][125] = {0};
		priority_queue<P, vector<P>, greater<P>> PQ;
		dist[0][0] = 0;
		PQ.push(P(0, 0));
		for(int i=0; i<N*N-1; i++){
			int r, c;
			do{
				r = PQ.top().second / N;
				c = PQ.top().second % N;
				PQ.pop();
			}while(visited[r][c]);
			visited[r][c] = true;

			for(int d=0; d<4; d++){
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
				if(dist[nr][nc] > dist[r][c] + map[nr][nc]){
					dist[nr][nc] = dist[r][c] + map[nr][nc];
					PQ.push(P(dist[nr][nc], nr*N+nc));
				}
			}
		}
		printf("Problem %d: %d\n", t, dist[N-1][N-1] + map[0][0]);
	}
}