#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 250;

int N, K, dp[MAX+1][MAX+1][MAX+1];

int pie(int n, int k, int prev){
	int &ret = dp[n][k][prev];
	if(ret != -1) return ret;
	if(prev > n) return ret = 0;
	if(k == K-1) return ret = 1;
	ret = 0;
	for(int i = prev; i <= n; ++i)
		ret += pie(n-i, k+1, i);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", pie(N, 0, 1));
}