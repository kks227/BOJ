#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int V, K, E;
	vector<int> F;
	vector<P> adj[500];
	scanf("%d %d %d", &V, &K, &E);
	for(int i=0; i<K; i++){
		int val;
		scanf("%d", &val);
		F.push_back(val-1);
	}
	for(int i=0; i<E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	int result = -1;
	unsigned int minVal = -1;
	for(int i=0; i<V; i++){
		int dist[500];
		bool visited[500] = {0};
		priority_queue<P, vector<P>, greater<P>> PQ;
		fill(dist, dist+V, INF);
		dist[i] = 0;
		PQ.push(P(0, i));

		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(visited[curr] && !PQ.empty());
			if(visited[curr]) break;
			visited[curr] = true;

			for(auto &p: adj[curr]){
				int next = p.first, d = p.second;
				if(dist[next] > dist[curr] + d){
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}

		unsigned int ds = 0;
		for(int i=0; i<K; i++)
			ds += dist[F[i]];
		if(minVal > ds){
			minVal = ds;
			result = i+1;
		}
	}
	printf("%d\n", result);
}