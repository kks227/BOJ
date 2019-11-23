#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M, A[MAX];
	vector<P> adj[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	int dist[MAX];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	bool visited[MAX] = {false,};
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second + dist[curr];
			if(dist[next] > d){
				dist[next] = d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	if(dist[N-1] == INF) puts("impossible");
	else{
		fill(visited, visited+N, false);
		int val[MAX] = {0,};
		val[0] = A[0];
		PQ.push(P(0, 0));
		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(visited[curr] && !PQ.empty());
			if(visited[curr]) break;
			visited[curr] = true;

			for(auto &p: adj[curr]){
				int next = p.first, d = p.second + dist[curr];
				if(dist[next] == d){
					val[next] = max(val[curr] + A[next], val[next]);
					PQ.push(P(dist[next], next));
				}
			}
		}
		printf("%d %d\n", dist[N-1], val[N-1]);
	}
}