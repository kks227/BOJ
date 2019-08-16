#include <cstdio>
using namespace std;
const int MAX = 100000;
const int MOD = 5000011;

int main(){
	int N, K, dp[MAX+1];
	scanf("%d %d", &N, &K);
	for(int i = 0; i <= N; ++i){
		if(i <= K) dp[i] = i+1;
		else dp[i] = (dp[i-1] + dp[i-K-1]) % MOD;
	}
	printf("%d\n", dp[N]);
}