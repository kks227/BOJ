#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 50000;
const long long INF = 1e18;
typedef pair<long long, int> P;

int main(){
	int N, M, F, S, E;
	vector<P> adj[2][MAX];
	scanf("%d %d %d %d %d", &N, &M, &F, &S, &E);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[0][u].push_back(P(w, v));
		adj[0][v].push_back(P(w, u));
		adj[1][u].push_back(P(w, MAX + v));
		adj[1][v].push_back(P(w, MAX + u));
	}
	for(int i = 0; i < F; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[0][u].push_back(P(0, MAX + v));
	}

	long long dist[2][MAX];
	fill(dist[0], dist[0] + N, INF);
	fill(dist[1], dist[1] + N, INF);
	dist[0][S] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, S));
	bool visited[2][MAX] = {false,};
	while(!PQ.empty()){
		int curr, k;
		do{
			curr = PQ.top().second % MAX;
			k = PQ.top().second / MAX;
			PQ.pop();
		}while(!PQ.empty() && visited[k][curr]);
		if(visited[k][curr]) break;
		visited[k][curr] = true;

		for(auto &p: adj[k][curr]){
			int next = p.second % MAX, nk = p.second / MAX;
			long long d = dist[k][curr] + p.first;
			if(d < dist[nk][next]){
				dist[nk][next] = d;
				PQ.push(P(d, nk*MAX + next));
			}
		}
	}
	printf("%lld\n", min(dist[0][E], dist[1][E]));
}