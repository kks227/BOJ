#include <cstdio>
#include <cstring>
using namespace std;

int dp[101][100][2];

int adjbits(int n, int k, bool prev){
	int &ret = dp[n][k][prev];
	if(ret != -1) return ret;
	if(n == 0) return !k;

	ret = adjbits(n-1, k, 0);
	if(!prev) ret += adjbits(n-1, k, 1);
	else if(k > 0) ret += adjbits(n-1, k-1, 1);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N, K;
		scanf("%d %d", &N, &K);
		if(N <= K) puts("0");
		else printf("%d\n", adjbits(N, K, 0));
	}
}