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
	int N, M, K;
	vector<P> adj[MAX];
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[v-1].push_back(P(w, u-1));
	}
	bool visited[MAX] = {false,};
	long long dist[MAX];
	fill(dist, dist + MAX, INF);
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i = 0; i < K; ++i){
		int k;
		scanf("%d", &k);
		dist[--k] = 0;
		PQ.push(P(0, k));
	}
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
			long long d = p.first + dist[curr];
			if(dist[next] > d){
				dist[next] = d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	P result(INF, INF);
	for(int i = 0; i < N; ++i)
		result = min(P(-dist[i], i+1), result);
	printf("%d\n%lld\n", result.second, -result.first);
}