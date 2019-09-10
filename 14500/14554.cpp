#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100000;
const int MOD = 1000000009;
const long long INF = 1e18;
typedef pair<long long, int> P;

int main(){
	int N, M, S, E;
	vector<P> adj[MAX];
	scanf("%d %d %d %d", &N, &M, &S, &E);
	--S; --E;
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u].push_back(P(w, v));
		adj[v].push_back(P(w, u));
	}

	long long dist[MAX];
	fill(dist, dist+MAX, INF);
	bool visited[MAX] = {false,};
	dist[S] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, S));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.second;
			long long d = dist[curr] + p.first;
			if(d < dist[next]){
				dist[next] = d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	vector<int> adj2[MAX];
	int indegree[MAX] = {0,}, result[MAX] = {0,};
	for(int i = 0; i < N; ++i){
		for(auto &p: adj[i]){
			int j = p.second;
			if(dist[i] + p.first == dist[j]){
				adj2[i].push_back(j);
				++indegree[j];
			}
		}
	}
	queue<int> Q;
	result[S] = 1;
	Q.push(S);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj2[curr]){
			result[next] = (result[next] + result[curr]) % MOD;
			if(--indegree[next] == 0) Q.push(next);
		}
	}
	printf("%d\n", result[E]);
}