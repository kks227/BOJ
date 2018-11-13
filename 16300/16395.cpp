#include <cstdio>
using namespace std;

unsigned long long dp[31][31];

unsigned long long C(int n, int k){
	unsigned long long &ret = dp[n][k];
	if(ret != 0) return ret;
	if(k == 1 || k == n) return ret = 1;
	return ret = C(n-1, k-1) + C(n-1, k);
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%llu\n", C(N, K));
}