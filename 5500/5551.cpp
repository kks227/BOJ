#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 3000;
const int MAX_E = 100000;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M, K, e[MAX_E][3];
	vector<P> adj[MAX];
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		scanf("%d %d %d", &e[i][0], &e[i][1], &e[i][2]);
		int &u = --e[i][0], &v = --e[i][1], &w = e[i][2];
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	int dist[MAX], result = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	fill(dist, dist+N, INF);
	for(int i = 0; i < K; ++i){
		int s;
		scanf("%d", &s);
		dist[--s] = 0;
		PQ.push(P(0, s));
	}
	bool visited[MAX] = {false,};
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;
		result = max(dist[curr], result);

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second + dist[curr];
			if(d < dist[next]){
				dist[next] = d;
				PQ.push(P(d, next));
			}
		}
	}

	for(int i = 0; i < M; ++i){
		int &u = e[i][0], &v = e[i][1], &w = e[i][2];
		if(dist[u] > dist[v]) swap(u, v);
		if(dist[u] + w <= dist[v]) continue;
		result = max((w + dist[u] + dist[v] + 1)/2, result);
	}
	printf("%d\n", result);
}