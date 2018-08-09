#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> P;
const long long INF = 1e18;

int main(){
	int N, M, K;
	vector<P> adj[10000];
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	bool visited[21][10000] = {0};
	long long dist[21][10000];
	for(int i=0; i<=20; i++)
		fill(dist[i], dist[i]+N, INF);
	dist[K][0] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, K*10000));

	while(!PQ.empty()){
		int k, curr;
		do{
			k = PQ.top().second / 10000;
			curr = PQ.top().second % 10000;
			PQ.pop();
			if(!visited[k][curr]) break;
		}while(!PQ.empty());
		if(visited[k][curr]) break;
		visited[k][curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first;
			long long d = p.second;
			if(dist[k][next] > dist[k][curr] + d){
				dist[k][next] = dist[k][curr] + d;
				PQ.push(P(dist[k][next], k*10000 + next));
			}
			if(k > 0 && dist[k-1][next] > dist[k][curr]){
				dist[k-1][next] = dist[k][curr];
				PQ.push(P(dist[k-1][next], (k-1)*10000 + next));
			}
		}
	}

	long long result = INF;
	for(int i=0; i<=K; i++)
		result = min(result, dist[i][N-1]);
	printf("%lld\n", result);
}