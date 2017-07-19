#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, T[2500], rSum[2501], dp[2501];

int crossing(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;

	ret = M + rSum[n];
	for(int i=1; i<n; i++)
		ret = min(ret, crossing(n-i) + M*2 + rSum[i]);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", T+i);
		rSum[i+1] = rSum[i] + T[i];
	}
	fill(dp, dp+N+1, -1);
	printf("%d\n", crossing(N));
}