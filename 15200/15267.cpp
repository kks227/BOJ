#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1000000;

int N, tSize[MAX];
vector<int> adj[MAX];

void dfs(int curr, int prev = -1){
	tSize[curr] = 1;
	for(int next: adj[curr]){
		if(next == prev) continue;
		dfs(next, curr);
		tSize[curr] += tSize[next];
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	for(int K = N/2; K > 1; --K){
		if(N%K != 0) continue;
		int cnt = 0;
		for(int i = 1; i < N; ++i)
			if(tSize[i]%K == 0) ++cnt;
		if(cnt == N/K-1) printf("%d ", N/K-1);
	}
	printf("%d\n", N-1);
}