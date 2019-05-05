#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 51;
const int MOD = 1000000007;

int N, dp[MAX];

int fibo(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n < 2) return ret = 1;
	return ret = (fibo(n-1) + fibo(n-2) + 1) % MOD;
}

int main(){
	scanf("%d", &N);
	fill(dp, dp+MAX, -1);
	printf("%d\n", fibo(N));
}