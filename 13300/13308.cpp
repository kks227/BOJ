#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;
const long long INF = 1e18;
typedef pair<int, long long> P;
typedef tuple<long long, int, int> Node;

int main(){
	int N, M, O[2500];
	vector<P> adj[2500];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", O+i);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	long long dist[2500][2500], result = INF;
	bool visited[2500][2500] = {false};
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dist[i][j] = INF;
	dist[0][0] = 0;
	priority_queue<Node, vector<Node>, greater<Node>> PQ;
	PQ.push(Node(0, 0, 0));
	while(!PQ.empty()){
		int u, v;
		long long dummy;
		do{
			tie(dummy, u, v) = PQ.top();
			PQ.pop();
		}while(visited[u][v] && !PQ.empty());
		if(visited[u][v]) break;
		visited[u][v] = true;
		if(u == N-1) result = min(dist[u][v], result);

		for(auto &p: adj[u]){
			int w = p.first, o = v;
			if(O[u] < O[v]) o = u;
			long long d = p.second, nd = dist[u][v] + d*O[o];
			if(nd < dist[w][o]){
				dist[w][o] = nd;
				PQ.push(Node(nd, w, o));
			}
		}
	}
	printf("%lld\n", result);
}