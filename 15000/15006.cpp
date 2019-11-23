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
	int N, M;
	vector<P> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(P(w, v));
		adj[v].push_back(P(w, u));
	}

	int to[MAX];
	long long dist[MAX];
	fill(to, to + N, -1);
	fill(dist, dist + N, INF);
	dist[1] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	bool visited[MAX] = {false,};
	PQ.push(P(0, 1));
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
				to[next] = curr;
				PQ.push(P(d, next));
			}
		}
	}

	fill(visited, visited + N, false);
	visited[0] = true;
	queue<int> Q;
	Q.push(0);
	int prev[MAX];
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(auto &p: adj[curr]){
			int next = p.second;
			if(next != to[curr] && !visited[next]){
				visited[next] = true;
				prev[next] = curr;
				Q.push(next);
			}
		}
	}
	if(!visited[1]) puts("impossible");
	else{
		vector<int> result;
		for(int i = 1; i != 0; i = prev[i])
			result.push_back(i);
		result.push_back(0);
		printf("%d", result.size());
		for(int i = result.size()-1; i >= 0; --i)
			printf(" %d", result[i]);
	}
}