#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int N = 1, in[10000];
vector<P> adj[10000];

int dijkstra(int S, bool flag){
	bool visited[10000] = {0};
	int dist[10000];
	fill(dist, dist+N, INF);
	dist[S] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, S));

	int r1, r2;
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;
		r1 = curr;
		r2 = dist[curr];

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	return (flag ? r2 : r1);
}

int main(){
	int u, v, w;
	while(scanf("%d %d %d", &u, &v, &w) > 0){
		N++; u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
		in[u]++; in[v]++;
	}
	int S = -1;
	for(int i=0; i<N; i++){
		if(in[i] == 1){
			S = dijkstra(i, false);
			break;
		}
	}
	printf("%d\n", dijkstra(S, true));
}