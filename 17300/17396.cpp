#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100000;
const long long INF = 1e18;
typedef pair<long long, int> P;

int main(){
	int N, M, visible[MAX];
	vector<P> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", visible+i);
	visible[N-1] = 0;
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if(!visible[v]) adj[u].push_back(P(w, v));
		if(!visible[u]) adj[v].push_back(P(w, u));
	}

	priority_queue<P, vector<P>, greater<P>> PQ;
	bool visited[MAX] = {false,};
	long long dist[MAX];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &e: adj[curr]){
			int next = e.second;
			long long d = e.first + dist[curr];
			if(d < dist[next]){
				dist[next] = d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	if(dist[N-1] == INF) dist[N-1] = -1;
	printf("%lld\n", dist[N-1]);
}