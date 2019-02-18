#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100000;
const long long INF = 1e18;
typedef pair<long long, int> P;
typedef tuple<int, int, int> Edge;

int main(){
	int N, M, K;
	vector<Edge> adj[MAX];
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		int u, v, c, t;
		scanf("%d %d %d %d", &u, &v, &c, &t);
		--u; --v;
		adj[u].push_back(Edge(v, c, t));
		adj[v].push_back(Edge(u, c, t));
	}

	int lo = 1, hi = 1e9;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;

		long long dist[MAX];
		bool visited[MAX] = {false,};
		fill(dist, dist+N, INF);
		priority_queue<P, vector<P>, greater<P>> PQ;
		dist[0] = 0;
		PQ.push(P(0, 0));
		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(visited[curr] && !PQ.empty());
			if(visited[curr] || dist[curr] > K) break;
			visited[curr] = true;

			for(auto &e: adj[curr]){
				int next, c, t;
				tie(next, c, t) = e;
				if(mid > t && (1LL*c*(mid-t) > K || 1LL*(mid-t)*(mid-t) > K)) continue;
				long long d = (mid > t ? 1LL*c*(mid-t)*(mid-t) : 0);
				if(dist[curr] + d < dist[next]){
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}
		(dist[N-1] <= K ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}