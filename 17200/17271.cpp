#include <cstdio>
using namespace std;
const int MAX_K = 10000;
const int MOD = 1000000007;

int main(){
	int n, k, dp[MAX_K+1] = {1, 1,};
	scanf("%d %d", &k, &n);
	for(int i = 2; i <= MAX_K; ++i){
		dp[i] = dp[i-1];
		if(i >= n) dp[i] = (dp[i] + dp[i-n]) % MOD;
	}
	printf("%d\n", dp[k]);
}