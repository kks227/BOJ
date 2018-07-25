#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int V, E, s, t;
	vector<P> adj[5000];
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}
	scanf("%d %d", &s, &t);
	s--; t--;

	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, s));
	int dist[5000];
	fill(dist, dist+V, INF);
	dist[s] = 0;
	bool visited[5000] = {false,};
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
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
	printf("%d\n", dist[t]);
}