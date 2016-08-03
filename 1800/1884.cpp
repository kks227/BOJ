#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

struct Edge{
	int c, d, next;
	Edge(): Edge(0, 0, -1){}
	Edge(int c1, int d1, int n1): c(c1), d(d1), next(n1){}
};

int N, R, K, dp[100][10001];
vector<Edge> adj[100];

int highway(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = 0;

	ret = IMPOSSIBLE;
	for(auto &e: adj[pos])
		if(k >= e.c) ret = min(ret, highway(e.next, k-e.c) + e.d);
	return ret;
}



int main(){
	scanf("%d %d %d", &K, &N, &R);
	for(int i=0; i<R; i++){
		int s, d, l, t;
		scanf("%d %d %d %d", &s, &d, &l, &t);
		adj[s-1].push_back(Edge(t, l, d-1));
	}
	memset(dp, -1, sizeof(dp));
	int result = highway(0, K);
	printf("%d\n", result==IMPOSSIBLE ? -1 : result);
}