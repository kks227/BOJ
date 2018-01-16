#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, dp[100000];
bool visited[100000];
vector<int> adj[100000];

int game(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;
	visited[curr] = true;
	ret = 0;
	for(int next: adj[curr])
		ret = max(game(next), ret);
	return ++ret;
}

int main(){
	int e[300000][2], d[100000] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		for(int j=0; j<2; j++){
			scanf("%d", &e[i][j]);
			d[e[i][j]]++;
		}
	}
	for(int i=0; i<M; i++){
		int u = e[i][0], v = e[i][1];
		if(d[u] < d[v]) adj[u].push_back(v);
		else if(d[u] > d[v]) adj[v].push_back(u);
	}

	int result = 1;
	fill(dp, dp+N, -1);
	for(int i=0; i<N; i++)
		if(!visited[i]) result = max(game(i), result);
	printf("%d\n", result);
}