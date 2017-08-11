#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000009;

int N, dp[33334][3];

int walk(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(n == N) return ret = !m;

	ret = 0;
	for(int i=!n; i<3; i++)
		ret = (ret + walk(n+1, (m+i)%3)) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", walk(0, 0));
}