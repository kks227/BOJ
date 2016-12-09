#include <cstdio>
#include <cstring>
using namespace std;

int K, N;
long long dp[64][65];

long long flea(int t, int k){
	long long &ret = dp[t][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = 0;
	if(t == N) return ret = 1;
	if(N-t < k) return ret = 1LL<<N-t;
	return ret = flea(t+1, k+1) + flea(t+1, k-1);
}

int main(){
	scanf("%d %d", &K, &N);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", flea(0, K));
}