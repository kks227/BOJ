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
	int N, M, K, S, X, Y;
	scanf("%d %d %d %d %d %d", &N, &M, &K, &S, &X, &Y);
	bool occupied[MAX] = {false,}, danger[MAX] = {false,}, visited[MAX] = {false,};
	queue<int> Q;
	vector<int> adj[MAX];
	for(int i = 0; i < K; ++i){
		int v;
		scanf("%d", &v);
		Q.push(--v);
		occupied[v] = danger[v] = true;
	}
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < S; ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(!danger[next]){
					danger[next] = true;
					Q.push(next);
				}
			}
		}
	}

	long long dist[MAX];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;

		for(int next: adj[curr]){
			if(occupied[next]) continue;
			long long d = dist[curr];
			if(next != N-1) d += (danger[next] ? Y : X);
			if(dist[next] > d){
				dist[next] = d;
				PQ.push(P(d, next));
			}
		}
	}
	printf("%lld\n", dist[N-1]);
}