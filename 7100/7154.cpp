#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 212;
const int S = MAX-2;
const int E = MAX-1;
const int INF = 1e9;

int main(){
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		int c[MAX][MAX] = {0}, d[MAX][MAX] = {0}, f[MAX][MAX] = {0};
		vector<int> adj[MAX];
		for(int i=0; i<N; i++){
			scanf("%d", &c[i][E]);
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
		for(int i=0; i<M; i++){
			int y, w[4], k = i+140;
			scanf("%d", &y);
			y--;
			c[S][k] = 1;
			adj[S].push_back(k);
			adj[k].push_back(S);
			for(int j=0; j<4; j++){
				scanf("%d", w+j);
				c[k][w[j]] = 1;
				d[w[j]][k] = y*4+4-j;
				d[k][w[j]] = -d[w[j]][k];
				adj[k].push_back(w[j]);
				adj[w[j]].push_back(k);
			}
		}

		int result = 0;
		while(1){
			int prev[MAX], dist[MAX];
			fill(dist, dist+MAX, INF);
			dist[S] = 0;
			bool inQ[MAX] = {0};
			inQ[S] = true;
			queue<int> Q;
			Q.push(S);

			while(!Q.empty()){
				int curr = Q.front(); Q.pop();
				inQ[curr] = false;
				for(int next: adj[curr]){
					if(dist[next] > dist[curr] + d[curr][next] && c[curr][next] - f[curr][next] > 0){
						dist[next] = dist[curr] + d[curr][next];
						prev[next] = curr;
						if(!inQ[next]){
							inQ[next] = true;
							Q.push(next);
						}
					}
				}
			}
			if(dist[E] == INF) break;

			int flow = INF;
			for(int i=E; i!=S; i=prev[i])
				flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
			for(int i=E; i!=S; i=prev[i]){
				result += flow*d[prev[i]][i];
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
		}
		printf("%d\n", -result);
	}
}