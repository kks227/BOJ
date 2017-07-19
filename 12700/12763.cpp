#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

struct Edge{
	int to, c, d;
	Edge(): Edge(-1, 0, 0){}
	Edge(int to1, int c1, int d1): to(to1), c(c1), d(d1){}
};

int N, T, M, dp[100][10001];
vector<Edge> adj[100];

int late(int curr, int t){
	int &ret = dp[curr][t];
	if(ret != -1) return ret;
	if(curr == N-1) return ret = 0;

	ret = IMPOSSIBLE;
	for(auto &e: adj[curr]){
		int next = e.to;
		if(t >= e.d) ret = min(ret, late(next, t-e.d)+e.c);
	}
	return ret;
}

int main(){
	int L;
	scanf("%d %d %d %d", &N, &T, &M, &L);
	for(int i=0; i<L; i++){
		int u, v, c, d;
		scanf("%d %d %d %d", &u, &v, &d, &c);
		u--; v--;
		adj[u].push_back(Edge(v, c, d));
		adj[v].push_back(Edge(u, c, d));
	}
	memset(dp, -1, sizeof(dp));
	int result = late(0, T);
	printf("%d\n", result <= M ? result : -1);
}