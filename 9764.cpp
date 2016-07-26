#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 100999;

int dp[2001][2001];

int cnt(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(n < m) return ret = 0;
	if(n == m) return ret = 1;
	if(n == 0) return ret = 1;
	return ret = (cnt(n-m, m+1) + cnt(n, m+1)) % MOD;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d\n", cnt(N, 1));
	}
}