#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
const int INF = 1e9;

int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, dp[MAX+1];

int seg(int n){
	int &ret = dp[n];
	if(ret != -INF) return ret;
	if(n == 0) return ret = 0;
	if(n == 1) return ret = -INF + 1;
	for(int i = 0; i < 10; ++i)
		if(cost[i] <= n) ret = max(seg(n-cost[i]) + i, ret);
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	fill(dp, dp+N+1, -INF);
	printf("%d\n", seg(N));
}