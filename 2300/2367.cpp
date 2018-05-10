#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 200;
const int MAX_D = 100;
const int S = MAX_N + MAX_D;
const int E = S + 1;
const int MAX = E + 1;

int main(){
	int N, K, D, c[MAX][MAX] = {0}, f[MAX][MAX] = {0};
	vector<int> adj[MAX];
	scanf("%d %d %d", &N, &K, &D);
	for(int i=0; i<D; i++){
		int u = MAX_N + i;
		adj[u].push_back(E);
		adj[E].push_back(u);
		scanf("%d", &c[u][E]);
	}
	for(int i=0; i<N; i++){
		int Z;
		scanf("%d", &Z);
		for(int j=0; j<Z; j++){
			int v;
			scanf("%d", &v);
			v = v - 1 + MAX_N;
			adj[i].push_back(v);
			adj[v].push_back(i);
			c[i][v] = 1;
		}
		adj[S].push_back(i);
		adj[i].push_back(S);
		c[S][i] = K;
	}

	int result = 0;
	while(1){
		int prev[MAX];
		fill(prev, prev+MAX, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty() && prev[E] == -1){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(prev[next] == -1 && c[curr][next] > f[curr][next]){
					prev[next] = curr;
					Q.push(next);
				}
			}
		}
		if(prev[E] == -1) break;

		result++;
		for(int i=E; i!=S; i=prev[i]){
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
	}
	printf("%d\n", result);
}