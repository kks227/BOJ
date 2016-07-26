#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, cost[50000], rSum[50001], dp[50000][4];

int maxPassenger(int n, int use){
	if(use == 0) return 0;
	if(n < M) return rSum[n+1];
	int &ret = dp[n][use];
	if(ret != -1) return ret;

	return ret = max(maxPassenger(n-1, use), maxPassenger(n-M, use-1) + rSum[n+1]-rSum[n-M+1]);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", cost+i);
		rSum[i+1] = rSum[i] + cost[i];
	}
	scanf("%d", &M);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxPassenger(N-1, 3));
}