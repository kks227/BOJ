#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M, K, S, E, p[30001] = {0};
	vector<P> adj[1000];
	scanf("%d %d %d %d %d", &N, &M, &K, &S, &E);
	S--; E--;
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}
	for(int i=1; i<=K; i++)
		scanf("%d", p+i);

	int dist[1000][1000];
	bool visited[1000][1000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i=0; i<N; i++)
		fill(dist[i], dist[i]+1000, INF);
	dist[S][0] = 0;
	PQ.push(P(0, S*1000));

	while(!PQ.empty()){
		int u, t;
		do{
			u = PQ.top().second / 1000, t = PQ.top().second % 1000;
			PQ.pop();
		}while(visited[u][t] && !PQ.empty());
		if(visited[u][t]) break;

		visited[u][t] = true;
		for(auto &e: adj[u]){
			int v = e.first, d = e.second;
			if(t < 999 && dist[v][t+1] > dist[u][t] + d){
				dist[v][t+1] = dist[u][t] + d;
				PQ.push(P(dist[v][t+1], v*1000 + t+1));
			}
		}
	}

	int sum = 0;
	for(int i=0; i<=K; i++){
		sum += p[i];
		int result = INF;
		for(int j=0; j<N; j++)
			result = min(result, dist[E][j] + sum*j);
		printf("%d\n", result);
	}
}