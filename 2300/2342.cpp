#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, tile[100001], dp[100000][5][5], cost[5][5] = {
	{0, 2, 2, 2, 2},
	{0, 0, 3, 4, 3},
	{0, 3, 0, 3, 4},
	{0, 4, 3, 0, 3},
	{0, 3, 4, 3, 0}
};

int minCost(int cur, int p1, int p2){
	if(cur == N) return 0;
	if(p1 > p2) swap(p1, p2);
	int &ret = dp[cur][p1][p2];
	if(ret != -1) return ret;

	if(tile[cur]==p1 || tile[cur]==p2) ret = minCost(cur+1, p1, p2) + 1;
	else ret = min(
		minCost(cur+1, tile[cur], p2) + cost[p1][tile[cur]],
		minCost(cur+1, p1, tile[cur]) + cost[p2][tile[cur]]
		);
	return ret;
}

int main(){
	for(N=0; ; N++){
		scanf("%d", tile+N);
		if(tile[N] == 0) break;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minCost(0, 0, 0));
}