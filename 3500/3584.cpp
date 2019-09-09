#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, depth[MAX], parent[MAX];
		vector<int> adj[MAX];
		scanf("%d", &N);
		fill(parent, parent+N, -1);
		for(int i = 0; i < N-1; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			parent[v] = u;
		}
		queue<int> Q;
		for(int i = 0; i < N; ++i){
			if(parent[i] == -1){
				depth[i] = 0;
				Q.push(i);
				break;
			}
		}
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				depth[next] = depth[curr] + 1;
				Q.push(next);
			}
		}

		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		if(depth[u] < depth[v]) swap(u, v);
		while(depth[u] > depth[v]) u = parent[u];
		while(u != v){
			u = parent[u];
			v = parent[v];
		}
		printf("%d\n", u+1);
	}
}