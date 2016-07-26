#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000009;

int N, K, dp[1000000][8], next[8][3] = {
	{1, 0, 0}, {1, 2, 0}, {3, 0, 4}, {1, 5, 0},
	{1, 6, 0}, {3, 0, 7}, {1, 0, 7}, {7, 7, 7}
};

int cntSecure(int p, int q){
	if(q == 7) return 0;
	if(p == N) return 1;
	int &ret = dp[p][q];
	if(ret != -1) return ret;

	ret = 1LL*(K-3)*cntSecure(p+1, 0) % MOD;
	for(int i=0; i<3; i++)
		ret = (ret + cntSecure(p+1, next[q][i])) % MOD;
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cntSecure(0, 0));
}