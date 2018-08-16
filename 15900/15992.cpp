#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000009;

int dp[1001][1001];

int add(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(m == 0) return ret = !n;
	if(n == 0) return ret = 0;

	ret = 0;
	for(int i=1; i<=3; i++)
		if(n >= i) ret = (ret + add(n-i, m-1)) % MOD;
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		printf("%d\n", add(N, M));
	}
}