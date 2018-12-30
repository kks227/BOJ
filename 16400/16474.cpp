#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2000;

int N, M, dp[MAX+1][MAX+1];
vector<int> adj[MAX];

int cord(int a, int b){
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	if(a == N || b == M) return ret = 0;

	ret = cord(a+1, b);
	auto iter = lower_bound(adj[a].begin(), adj[a].end(), b);
	if(iter != adj[a].end()) ret = max(cord(a+1, (*iter)+1) + 1, ret);
	return ret;
}

int main(){
	int N2H[MAX], M2H[MAX], K;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		N2H[val-1] = i;
	}
	for(int i = 0; i < M; ++i){
		int val;
		scanf("%d", &val);
		M2H[val-1] = i;
	}
	scanf("%d", &K);
	for(int i = 0; i < K; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[N2H[u-1]].push_back(M2H[v-1]);
	}
	for(int i = 0; i < N; ++i)
		sort(adj[i].begin(), adj[i].end());
	memset(dp, -1, sizeof(dp));
	printf("%d\n", K-cord(0, 0));
}