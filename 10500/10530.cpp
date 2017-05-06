#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<P> adj[10000];
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(P(b, c));
		adj[b].push_back(P(a, c));
	}

	int dist[10000];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	bool visited[10000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;

		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	long long result = 0;
	queue<int> Q;
	Q.push(N-1);
	fill(visited, visited+N, false);
	visited[N-1] = true;
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[curr] == dist[next] + d){
				result += d;
				if(!visited[next]) Q.push(next);
				visited[next] = true;
			}
		}
	}
	printf("%lld\n", result*2);
}