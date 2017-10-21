#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, M, dp[20][20];
char adj[20][20];

int ppath(int u, int v){
	int &ret = dp[u][v];
	if(ret != -1) return ret;
	if(u == 0 && v == 1 || u == 1 && v == 0) return ret = 0;

	ret = INF;
	for(int i=0; i<N; i++){
		if(!adj[u][i]) continue;
		for(int j=0; j<N; j++){
			if(!adj[v][j]) continue;
			if(adj[u][i] == adj[v][j]) ret = min(ppath(i, j)+2, ret);
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		char c;
		scanf("%d %d %c", &u, &v, &c);
		adj[u][v] = adj[v][u] = c;
	}
	memset(dp, -1, sizeof(dp));

	int result = INF;
	for(int i=0; i<N; i++){
		result = min(ppath(i, i), result);
		for(int j=i+1; j<N; j++)
			if(adj[i][j]) result = min(ppath(i, j)+1, result);
	}
	if(result == INF) result = -1;
	printf("%d\n", result);
}