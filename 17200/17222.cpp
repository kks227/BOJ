#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 200;
const int MAX = MAX_N + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9 * 2 + 1;

int main(){
	int N, M, val[MAX_N], c[MAX][MAX] = {0,}, f[MAX][MAX] = {0,};
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", val+i);
		adj[E].push_back(i);
		adj[i].push_back(E);
		c[i][E] = INF;
	}
	for(int j = N; j < N+M; ++j){
		scanf("%d", val+j);
		adj[S].push_back(j);
		adj[j].push_back(S);
		c[S][j] = val[j];
	}
	for(int j = N; j < N+M; ++j){
		int K;
		scanf("%d", &K);
		for(int k = 0; k < K; ++k){
			int i;
			scanf("%d", &i);
			--i;
			adj[i].push_back(j);
			adj[j].push_back(i);
			c[j][i] = val[i];
		}
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

		int flow = INF;
		for(int i = E; i != S; i = prev[i])
			flow = min(c[prev[i]][i]-f[prev[i]][i], flow);
		total += flow;
		for(int i = E; i != S; i = prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
	}
	printf("%d\n", total);
}