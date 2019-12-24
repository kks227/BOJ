#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 300000;

int main(){
	int N, M, S, E;
	vector<int> adj[MAX];
	scanf("%d %d %d %d", &N, &M, &S, &E);
	--S; --E;
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < N-1; ++i){
		adj[i].push_back(i+1);
		adj[i+1].push_back(i);
	}

	int dist[MAX];
	fill(dist, dist+N, -1);
	dist[S] = 0;
	queue<int> Q;
	Q.push(S);
	while(dist[E] == -1){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(dist[next] == -1){
				dist[next] = dist[curr] + 1;
				Q.push(next);
			}
		}
	}
	printf("%d\n", dist[E]);
}