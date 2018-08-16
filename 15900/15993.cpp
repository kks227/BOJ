#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000009;

int dp[100001][2];

int add(int n, bool flag){
	int &ret = dp[n][flag];
	if(ret != -1) return ret;
	if(n == 0) return ret = !flag;

	ret = 0;
	for(int i=1; i<=3; i++)
		if(n >= i) ret = (ret + add(n-i, !flag)) % MOD;
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d %d\n", add(N, true), add(N, false));
	}
}