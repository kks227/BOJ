#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int V, E, T[2], D[2];
	bool target[2][10000] = {0};
	vector<P> adj[10000];
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}
	for(int i=0; i<2; i++){
		scanf("%d %d", T+i, D+i);
		for(int j=0; j<T[i]; j++){
			int val;
			scanf("%d", &val);
			target[i][val-1] = true;
		}
	}

	int dist[2][10000];
	for(int i=0; i<2; i++){
		bool visited[10000] = {0};
		priority_queue<P, vector<P>, greater<P>> PQ;
		fill(dist[i], dist[i]+10000, INF);
		for(int j=0; j<V; j++){
			if(target[i][j]){
				dist[i][j] = 0;
				PQ.push(P(0, j));
			}
		}

		for(int j=0; !PQ.empty(); j++){
			int u;
			do{
				u = PQ.top().second;
				PQ.pop();
			}while(visited[u] && !PQ.empty());
			if(visited[u]) break;

			visited[u] = true;
			for(auto &p: adj[u]){
				int v = p.first, d = p.second;
				if(dist[i][v] > dist[i][u] + d){
					dist[i][v] = dist[i][u] + d;
					PQ.push(P(dist[i][v], v));
				}
			}
		}
	}

	int result = INF;
	for(int i=0; i<V; i++){
		if(target[0][i] || target[1][i]) continue;
		if(dist[0][i] <= D[0] && dist[1][i] <= D[1])
			result = min(result, dist[0][i] + dist[1][i]);
	}
	if(result == INF) result = -1;
	printf("%d\n", result);
}