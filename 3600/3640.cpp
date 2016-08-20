#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int MAX_V = 2*MAX_N;
const int INF = 1000000000;

int main(){
	int N, M;
	while(scanf("%d %d", &N, &M) > 0){
		int c[MAX_V][MAX_V] = {0}, d[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
		vector<int> adj[MAX_V];
		for(int i=0; i<M; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u = (u-1)*2+1;
			v = (v-1)*2;
			c[u][v] = 1;
			d[u][v] = w;
			d[v][u] = -w;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0; i<N; i++){
			c[i*2][i*2+1] = 1;
			adj[i*2].push_back(i*2+1);
			adj[i*2+1].push_back(i*2);
		}

		int result = 0, S = 1, E = (N-1)*2;
		for(int k=0; k<2; k++){
			int prev[MAX_V], dist[MAX_V];
			bool inQ[MAX_V] = {0};
			queue<int> Q;
			fill(prev, prev+MAX_V, -1);
			fill(dist, dist+MAX_V, INF);
			dist[S] = 0;
			inQ[S] = true;
			Q.push(S);

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for(int next: adj[curr]){
					if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]){
						dist[next] = dist[curr] + d[curr][next];
						prev[next] = curr;
						if(!inQ[next]){
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if(prev[E] == -1) break;

			for(int i=E; i!=S; i=prev[i]){
				result += d[prev[i]][i];
				f[prev[i]][i]++;
				f[i][prev[i]]--;
			}
		}
		printf("%d\n", result);
	}
}