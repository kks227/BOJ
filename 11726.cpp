#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 10007;

int N, dp[1000];

int tiling(int pos){
	if(pos > N) return 0;
	if(pos == N) return 1;
	int &ret = dp[pos];
	if(ret != -1) return ret;
	return ret = (tiling(pos+1) + tiling(pos+2)) % MOD;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tiling(0));
}