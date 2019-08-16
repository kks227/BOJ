#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_D = 18;
const int INF = 1e9;

class Tree{
public:
	void input(){
		scanf("%d", &N);
		for(int i = 0; i < N-1; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		memset(parent, -1, sizeof(parent));
		depth[0] = 0;
		fill(visited, visited + N, false);
		makeTreeByDFS(0);

		for(int j = 0; j < MAX_D-1; ++j)
			for(int i = 1; i < N; ++i)
				if(parent[i][j] != -1) parent[i][j+1] = parent[ parent[i][j] ][j];
	}

	int solve(int r, int u, int v){
		int w[3] = {LCA(u, r), LCA(v, r), LCA(u, v)}, r1 = -1, r2 = -1;
		for(int i = 0; i < 3; ++i){
			if(depth[w[i]] > r1){
				r1 = depth[w[i]];
				r2 = w[i];
			}
		}
		return r2;
	}

private:
	int N, parent[MAX][MAX_D], depth[MAX];
	vector<int> adj[MAX];
	bool visited[MAX];

	int LCA(int u, int v){
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
		return u;
	}

	void makeTreeByDFS(int curr){
		visited[curr] = true;
		for(int next: adj[curr]){
			if(!visited[next]){
				parent[next][0] = curr;
				depth[next] = depth[curr]+1;
				makeTreeByDFS(next);
			}
		}
	}
};



int main(){
	Tree T;
	T.input();
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int r, u, v;
		scanf("%d %d %d", &r, &u, &v);
		printf("%d\n", T.solve(r-1, u-1, v-1) + 1);
	}
}