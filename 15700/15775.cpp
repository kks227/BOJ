#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const long long INF = 1e18;
typedef pair<long long, long long> P;

int main(){
	int N, M, K, s[250000];
	vector<P> adj[250000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}
	scanf("%d", &K);
	for(int i=0; i<K; i++){
		scanf("%d", s+i);
		s[i]--;
	}

	long long dist[250000], result[250000] = {0};
	fill(dist, dist+N, INF);
	bool visited[250000] = {false,};
	priority_queue<P, vector<P>, greater<P>> PQ;
	int from[250000];
	fill(from, from+N, N);
	for(int i=0; i<K; i++){
		PQ.push(P(0, s[i]));
		dist[s[i]] = 0;
		from[s[i]] = i;
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
			int next = p.first, d = p.second;
			if(visited[next]){
				if(curr == next) result[from[curr]] += d;
				else{
					long long temp = dist[curr] - dist[next];
					result[from[next]] += d + temp;
					result[from[curr]] += d - temp;
				}
			}
			else if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				from[next] = from[curr];
				PQ.push(P(dist[next], next));
			}
			else if(dist[next] == dist[curr] + d)
				from[next] = min(from[curr], from[next]);
		}
	}
	long long temp = 0;
	for(int i=0; i<K; i++)
		printf("%lld.%1d\n", result[i]/2, result[i]%2 ? 5 : 0);
}