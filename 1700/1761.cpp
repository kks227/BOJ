#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 40000;
const int MAX_D = 16; // roundup log(2, MAX)
typedef pair<int, int> P;

int N, M, parent[MAX][MAX_D], depth[MAX], dist[MAX];
vector<P> adj[MAX];
bool visited[MAX];

void dfs(int curr){
	visited[curr] = true;
	for(auto &p: adj[curr]){
		int next = p.first;
		if(!visited[next]){
			parent[next][0] = curr;
			depth[next] = depth[curr]+1;
			dist[next] = dist[curr] + p.second;
			dfs(next);
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}
	memset(parent, -1, sizeof(parent));
	depth[0] = 0;
	dist[0] = 0;
	dfs(0);

	for(int j = 0; j < MAX_D-1; ++j)
		for(int i = 1; i < N; ++i)
			if(parent[i][j] != -1) parent[i][j+1] = parent[ parent[i][j] ][j];

	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int u, v, u1, v1;
		scanf("%d %d", &u, &v);
		u1 = --u;
		v1 = --v;

		if(depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];
		for(int j = 0; diff > 0; ++j){
			if(diff % 2) u = parent[u][j];
			diff /= 2;
		}
		if(u != v){
			for(int j = MAX_D-1; j >= 0; --j){
				if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		printf("%d\n", dist[u1] + dist[v1] - 2*dist[u]);
	}
}