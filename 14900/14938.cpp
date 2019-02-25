#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX = 100;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M, D, w[MAX];
	vector<P> adj[MAX];
	scanf("%d %d %d", &N, &D, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", w+i);
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	int result = 0;
	for(int i = 0; i < N; ++i){
		int dist[MAX];
		fill(dist, dist + N, INF);
		bool visited[MAX] = {false,};
		priority_queue<P, vector<P>, greater<P>> PQ;
		PQ.push(P(0, i));
		dist[i] = 0;
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
				if(dist[next] > dist[curr] + d){
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}
		}

		int temp = 0;
		for(int j = 0; j < N; ++j)
			if(dist[j] <= D) temp += w[j];
		result = max(temp, result);
	}
	printf("%d\n", result);
}