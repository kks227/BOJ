#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 450;
const int MAX_K = 4000;
const long long INF = 1e18;
typedef pair<long long, int> P;
typedef tuple<int, int, int> Edge;

int main(){
	int N, M, S, E, K1, K2;
	vector<Edge> adj[MAX];
	scanf("%d %d %d %d", &N, &M, &K1, &K2);
	++K1; ++K2;
	for(int i = 0; i < M; ++i){
		int u, v, w, c;
		scanf("%d %d %d %d", &u, &v, &w, &c);
		--u; --v;
		adj[u].push_back(Edge(v, w, c));
		adj[v].push_back(Edge(u, w, c));
	}
	scanf("%d %d", &S, &E);
	--S; --E;

	vector<long long> dist[MAX];
	vector<bool> visited[MAX];
	for(int i = 0; i < MAX; ++i){
		dist[i].resize(K1*K2, INF);
		visited[i].resize(K1*K2, false);
	}
	priority_queue<P, vector<P>, greater<P>> PQ;
	dist[S][0] = 0;
	PQ.push(P(0, S));
	while(!PQ.empty()){
		int curr, k1, k2;
		do{
			curr = PQ.top().second % MAX;
			k1 = PQ.top().second / MAX / K2;
			k2 = PQ.top().second / MAX % K2;
			if(curr == E && k1 == K1-1 && k2 == K2-1){
				printf("%lld\n", PQ.top().first);
				return 0;
			}
			PQ.pop();
		}while(!PQ.empty() && visited[curr][k1*K2+k2]);
		if(visited[curr][k1*K2+k2]) break;
		visited[curr][k1*K2+k2] = true;

		for(auto &e: adj[curr]){
			int next, c, nk1 = k1, nk2 = k2;
			long long d;
			tie(next, d, c) = e;
			d += dist[curr][k1*K2+k2];
			if(c == 1 && nk1++ == K1-1) continue;
			if(c == 2 && nk2++ == K2-1) continue;
			if(dist[next][nk1*K2+nk2] > d){
				dist[next][nk1*K2+nk2] = d;
				PQ.push(P(d, (nk1*K2+nk2)*MAX + next));
			}
		}
	}
	puts("-1");
}