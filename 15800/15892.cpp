#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> adj[300];
	int c[300][300] = {0}, f[300][300] = {0};
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = c[v][u] += w;
	}

	int result = 0;
	while(1){
		int prev[300];
		fill(prev, prev+N, -1);
		queue<int> Q;
		Q.push(0);
		while(!Q.empty() && prev[N-1] < 0){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(prev[next] < 0 && c[curr][next]-f[curr][next] > 0){
					Q.push(next);
					prev[next] = curr;
				}
			}
		}
		if(prev[N-1] < 0) break;

		int flow = INF;
		for(int i=N-1; i!=0; i=prev[i])
			flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
		for(int i=N-1; i!=0; i=prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		result += flow;
	}
	printf("%d\n", result);
}