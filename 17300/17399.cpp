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

	int solve(int u, int v, int w){
		int x[3] = {u, v, w}, y[3] = {median(u, v), median(u, w), median(v, w)};
		for(int i = 0; i < 3; ++i)
			if(y[i] == -1) return -1;

		int r1 = INF, r2 = -1;
		for(int i = 0; i < 3; ++i){
			int d[3];
			for(int j = 0; j < 3; ++j)
				d[j] = distance(x[j], y[i]);
			if(d[0] != d[1] || d[0] != d[2]) continue;
			if(r1 > d[0]){
				r1 = d[0];
				r2 = y[i] + 1;
			}
		}
		return r2;
	}

private:
	int N, parent[MAX][MAX_D], depth[MAX];
	vector<int> adj[MAX];
	bool visited[MAX];

	int median(int u, int v){
		if(distance(u, v)%2 == 1) return -1;

		if(depth[u] < depth[v]) swap(u, v);
		int w = LCA(u, v), d = depth[u] - depth[w], e = depth[v] - depth[w], f = (d+e)/2;
		return kthParent(u, f);
	}

	int distance(int u, int v){
		return depth[u] + depth[v] - depth[LCA(u, v)]*2;
	}

	int kthParent(int u, int k){
		for(int j = 0; k > 0 && j <= MAX_D; ++j){
			if(k & 1<<j) u = parent[u][j];
			if(u == -1) return -1;
		}
		return u;
	}

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
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		printf("%d\n", T.solve(u-1, v-1, w-1));
	}
}