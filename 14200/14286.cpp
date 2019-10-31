#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 500;
const int INF = 1e9;

int main(){
	int N, M, S, E, c[MAX][MAX] = {0,}, f[MAX][MAX] = {0,};
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		c[u][v] = c[v][u] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d %d", &S, &E);
	--S; --E;

	int total = 0;
	while(1){
		int prev[MAX];
		fill(prev, prev+N, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(prev[next] == -1 && c[curr][next]-f[curr][next] > 0){
					Q.push(next);
					prev[next] = curr;
				}
			}
		}
		if(prev[E] == -1) break;

		int flow = INF;
		for(int i = E; i != S; i = prev[i])
			flow = min(c[prev[i]][i]-f[prev[i]][i], flow);
		for(int i = E; i != S; i = prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
}