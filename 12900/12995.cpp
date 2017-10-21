#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int N, K, dp[50][50][51][2];
vector<int> adj[50], child[50];
bool visited[50];

void dfs(int curr){
	visited[curr] = true;
	for(int next: adj[curr]){
		if(!visited[next]){
			child[curr].push_back(next);
			dfs(next);
		}
	}
}

int tw(int root, int limit, int k, bool ps=false){
	int &ret = dp[root][limit][k][ps];
	if(ret != -1) return ret;
	if(k == 0) return ret = 1;
	if(child[root].empty()) return ret = (k <= 1);

	ret = 0;
	if(!ps){
		for(int next: child[root])
			ret = (tw(next, child[next].size(), k, false) + ret) % MOD;
	}
	if(limit == 1){
		int next = child[root][0];
		ret = (tw(next, child[next].size(), k-1, true) + ret) % MOD; 
	}
	else{
		for(int i=0; i<k; i++){
			int next = child[root][limit-1];
			long long temp = tw(root, limit-1, k-i, true) * tw(next, child[next].size(), i, true);
			ret = (temp + ret) % MOD;
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tw(0, child[0].size(), K));
}