#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 987654321;

int dp[10000];

int handshake(int n){
	if(n == 0) return 1;
	int &ret = dp[n];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=0; i<=n-2; i+=2)
		ret = (ret + 1LL * handshake(i) * handshake(n-2-i)) % MOD;
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<=N-2; i+=2)
		result = (result + 1LL * handshake(i) * handshake(N-2-i)) % MOD;
	printf("%d\n", result);
}