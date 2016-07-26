#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <utility>
using namespace std;
typedef pair<int, int> P;

class Edge{
public:
	int u, v, w;
	bool used;
	Edge(): Edge(0, 0, 0){}
	Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1), used(false){}
};

int N, S, D;
vector<Edge> edge;
set<int> pre[500], suc[500];

int dijkstra(bool erase=false){
	vector<int> dist(N, 0x7FFFFFFF);
	vector<bool> visited(N, false);
	priority_queue<P> pq;
	pq.push(P(0, S));
	dist[S] = 0;
	for(int i=0; i<N; i++){
		if(pq.empty()) break;
		int u;
		while(!pq.empty()){
			u = pq.top().second;
			pq.pop();
			if(!visited[u]) break;
		}
		if(visited[u]) break;
		visited[u] = true;
		for(auto p: suc[u]){
			Edge &e = edge[p];
			if(e.used) continue;
			if(dist[e.v] > dist[u]+e.w){
				dist[e.v] = dist[u]+e.w;
				pq.push(P(-dist[e.v], e.v));
			}
		}
	}
	if(dist[D] == 0x7FFFFFFF) return -1;
	if(erase){
		queue<P> q;
		q.push(P(D, dist[D]));
		visited = vector<bool>(N, false);
		while(!q.empty()){
			P pp = q.front();
			q.pop();
			if(visited[pp.first]) continue;
			visited[pp.first] = true;
			for(auto p: pre[pp.first]){
				Edge &e = edge[p];
				if(dist[e.u]+e.w == pp.second){
					q.push(P(e.u, dist[e.u]));
					e.used = true;
				}
			}
		}
	}
	return dist[D];
}

int main(){
	while(1){
		int M;
		scanf("%d %d", &N, &M);
		if(N==0) break;
		for(int i=0; i<N; i++){
			pre[i].clear();
			suc[i].clear();
		}
		edge.clear();
		scanf("%d %d", &S, &D);
		for(int i=0; i<M; i++){
			int U, V, W;
			scanf("%d %d %d", &U, &V, &W);
			edge.push_back(Edge(U, V, W));
			suc[U].insert(i);
			pre[V].insert(i);
		}
		if(dijkstra(true) == -1){
			puts("-1");
			continue;
		}
		printf("%d\n", dijkstra());
	}
}