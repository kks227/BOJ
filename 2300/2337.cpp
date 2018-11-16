#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int N, M, dp[150][151], result = IMPOSSIBLE;
vector<int> adj[150];

void dfs(int curr, int prev){
	fill(dp[curr], dp[curr]+M+1, IMPOSSIBLE);
	dp[curr][1] = 0;
	for(int next: adj[curr]){
		if(next == prev) continue;

		dfs(next, curr);
		for(int k = M; k > 0; --k){
			++dp[curr][k];
			for(int i = 1; i < k; ++i)
				dp[curr][k] = min(dp[curr][i] + dp[next][k-i], dp[curr][k]);
		}
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	int result = IMPOSSIBLE;
	for(int i = 0; i < N; ++i)
		result = min(dp[i][M] + (i > 0), result);
	printf("%d\n", result);
}