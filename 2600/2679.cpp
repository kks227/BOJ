#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, M, S, E, c[1000][1000], f[1000][1000], dp[1000];
vector<int> adj[1000];

int onePath(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;
	if(curr == E) return ret = INF;

	ret = 0;
	for(int next: adj[curr])
		ret = max(ret, min(onePath(next), c[curr][next]));
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d %d", &N, &M, &S, &E);
		for(int i=0; i<M; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(v);
			adj[v].push_back(u);
			c[u][v] = w;
		}
		fill(dp, dp+N, -1);

		int total = 0;
		while(1){
			int prev[1000];
			bool visited[1000] = {0};
			visited[S] = true;
			queue<int> Q;
			Q.push(S);
			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				for(int next: adj[curr]){
					if(!visited[next] && c[curr][next]-f[curr][next] > 0){
						visited[next] = true;
						prev[next] = curr;
						Q.push(next);
					}
				}
			}
			if(!visited[E]) break;

			int flow = INF;
			for(int i=E; i!=S; i=prev[i])
				flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
			for(int i=E; i!=S; i=prev[i]){
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
			total += flow;
		}
		printf("%.3lf\n", 1.0*total/onePath(S));

		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		for(int i=0; i<N; i++)
			adj[i].clear();
	}
}