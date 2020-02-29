#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_D = 18; // roundup log(2, 100000)
const int INF = 1e9;

class CentroidDecomposition{
public:
	int initialize(){
		int M;
		scanf("%d %d", &N, &M);
		for(int i = 1; i < N; ++i){
			int j;
			scanf("%d", &j);
			--j;
			adj[i].insert(j);
			adj[j].insert(i);
		}
		fill(color, color+N, false);

		memset(parent, -1, sizeof(parent));
		fill(depth, depth + N, -1);
		depth[0] = 0;
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(depth[next] < 0){
					depth[next] = depth[curr] + 1;
					parent[next][0] = curr;
					Q.push(next);
				}
			}
		}
		for(int j = 0; j < MAX_D-1; ++j)
			for(int i = 1; i < N; ++i)
				if(parent[i][j] != -1)
					parent[i][j+1] = parent[parent[i][j]][j];

		fill(cParent, cParent + N, -1);
		construct(0);
		return M;
	}

	void update(int u){
		color[u] = !color[u];
		int v = u;
		while(1){
			int d = getDist(u, v);
			if(color[u]) S[v].insert(d);
			else S[v].erase(S[v].find(d));
			if(cParent[v] == -1) break;
			v = cParent[v];
		}
	}

	int getNearest(int u){
		int result = INF, v = u;
		while(1){
			int d = getDist(u, v);
			if(!S[v].empty()) result = min(d + *S[v].begin(), result);
			if(cParent[v] == -1) break;
			v = cParent[v];
		}

		if(result == INF) result = -1;
		return result;
	}

private:
	int N, parent[MAX][MAX_D], depth[MAX], tSize[MAX], cParent[MAX];
	set<int> adj[MAX];
	bool color[MAX];
	multiset<int> S[MAX];

	void construct(int curr, int prev = -1){
		int n = dfs1(curr);
		int root = dfs2(n, curr);
		cParent[root] = prev;
		while(!adj[root].empty()){
			int next = *adj[root].begin();
			if(next != prev){
				adj[root].erase(next);
				adj[next].erase(root);
				construct(next, root);
			}
		}
	}

	int getLCA(int u, int v){
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

	int getDist(int u, int v){
		int w = getLCA(u, v);
		return depth[u] + depth[v] - depth[w]*2;
	}

	int dfs1(int curr, int prev = -1){
		tSize[curr] = 1;
		for(int next: adj[curr])
			if(next != prev) tSize[curr] += dfs1(next, curr);
		return tSize[curr];
	}

	int dfs2(int n, int curr, int prev = -1){
		for(int next: adj[curr]){
			if(next != prev && tSize[next] > n/2)
				return dfs2(n, next, curr);
		}
		return curr;
	}
};

int main(){
	CentroidDecomposition CD;
	int M = CD.initialize();
	for(int i = 0; i < M; ++i){
		int o, u;
		scanf("%d %d", &o, &u);
		if(o == 1) CD.update(u-1);
		else printf("%d\n", CD.getNearest(u-1));
	}
}