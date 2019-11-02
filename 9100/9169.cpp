#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 300;
const int MAX = MAX_N + 2;
const int S = MAX - 2;
const int E = MAX - 1;

int main(){
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		int c[MAX][MAX] = {0,}, f[MAX][MAX] = {0,};
		vector<int> adj[MAX];
		for(int i = 0; i < N; ++i){
			int k;
			scanf("%d", &k);
			int u = (k ? E : S);
			adj[u].push_back(i);
			adj[i].push_back(u);
			c[u][i] = c[i][u] = 1;
		}
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			c[u][v] = c[v][u] = 1;
		}

		int total = 0;
		while(1){
			int prev[MAX];
			fill(prev, prev+MAX, -1);
			queue<int> Q;
			Q.push(S);
			while(!Q.empty() && prev[E] == -1){
				int curr = Q.front(); Q.pop();
				for(int next: adj[curr]){
					if(prev[next] == -1 && c[curr][next]-f[curr][next] > 0){
						prev[next] = curr;
						Q.push(next);
					}
				}
			}
			if(prev[E] == -1) break;

			++total;
			for(int i = E; i != S; i = prev[i]){
				++f[prev[i]][i];
				--f[i][prev[i]];
			}
		}
		printf("%d\n", total);
	}
}