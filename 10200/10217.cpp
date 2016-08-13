#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

struct Edge{
	int next, cost, dist;
	Edge(): Edge(-1, 0, 0){}
	Edge(int n, int c, int d): next(n), cost(c), dist(d){}
};

int N, M, K, dp[100][10001];
vector<Edge> adj[100];

int KCM(int curr, int money){
	int &ret = dp[curr][money];
	if(ret != -1) return ret;
	if(curr == N-1) return ret = 0;

	ret = IMPOSSIBLE;
	for(auto &e: adj[curr])
		if(money >= e.cost) ret = min(ret, KCM(e.next, money - e.cost) + e.dist);
	return ret;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d", &N, &M, &K);
		for(int i=0; i<N; i++)
			adj[i].clear();
		for(int i=0; i<K; i++){
			int u, v, x, d;
			scanf("%d %d %d %d", &u, &v, &x, &d);
			adj[u-1].push_back(Edge(v-1, x, d));
		}
		memset(dp, -1, sizeof(dp));
		int result = KCM(0, M);
		if(result != IMPOSSIBLE) printf("%d\n", result);
		else puts("Poor KCM");
	}
}