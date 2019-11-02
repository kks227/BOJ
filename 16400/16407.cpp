#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 30;
const int MAX = MAX_N*MAX_N*2 + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, K, c[MAX][MAX] = {0,}, f[MAX][MAX] = {0,}, cost[26];
	scanf("%d %d %d", &C, &R, &K);
	vector<int> adj[MAX];
	char map[MAX_N][MAX_N];
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}
	for(int i = 0; i < K; ++i)
		scanf("%d", cost+i);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int u1 = (i*MAX_N + j)*2, u2 = u1 + 1;
			c[u1][u2] = (islower(map[i][j]) ? cost[map[i][j]-'a'] : INF);
			adj[u1].push_back(u2);
			adj[u2].push_back(u1);
			if(map[i][j] == 'B'){
				c[S][u2] = INF;
				adj[S].push_back(u2);
				adj[u2].push_back(S);
			}
			for(int d = 0; d < 4; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				int v = (nr < 0 || nr >= R || nc < 0 || nc >= C ? E : (nr*MAX_N+nc)*2);
				c[u2][v] = INF;
				adj[u2].push_back(v);
				adj[v].push_back(u2);
			}
		}
	}

	long long result = 0;
	while(1){
		int prev[MAX];
		fill(prev, prev + MAX, -1);
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
		for(int i = E; i != S; i = prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		result += flow;
	}
	if(result >= INF) result = -1;
	printf("%lld\n", result);
}