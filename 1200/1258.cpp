#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, S = 200, E = 201, c[202][202] = {0}, d[202][202] = {0}, f[202][202] = {0};
	scanf("%d", &N);
	vector<int> adj[202];
	for(int i=0; i<N; i++){
		int a = i*2, b = i*2+1;
		adj[S].push_back(a); adj[a].push_back(S);
		adj[b].push_back(E); adj[E].push_back(b);
		c[S][a] = c[b][E] = 1;
		for(int j=0; j<N; j++){
			b = j*2+1;
			scanf("%d", &d[a][b]);
			d[b][a] = -d[a][b];
			adj[a].push_back(b); adj[b].push_back(a);
			c[a][b] = 1;
		}
	}

	int result = 0;
	while(1){
		queue<int> Q;
		Q.push(S);
		bool inQ[202] = {0};
		inQ[S] = true;
		int dist[202], prev[202];
		fill(dist, dist+202, INF);
		dist[S] = 0;
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for(int next: adj[curr]){
				if(dist[next] > dist[curr]+d[curr][next] && c[curr][next]-f[curr][next] > 0){
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

		for(int i=E; i!=S; i=prev[i]){
			f[prev[i]][i]++;
			f[i][prev[i]]--;
			result += d[prev[i]][i];
		}
	}
	printf("%d\n", result);
}