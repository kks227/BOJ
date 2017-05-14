#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int N, dp[100001][2];

int color(int n, bool k){
	int &ret = dp[n][k];
	if(ret != -1) return ret;
	if(n == 1) return ret = k;

	if(k) ret = (1LL*color(n-1, true) * (n-1) % MOD * (n-1) % MOD + color(n-1, false)) % MOD;
	else ret = 1LL*color(n-1, true) * n % MOD * (n-1) % MOD * (n-1) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", color(N, false));
}