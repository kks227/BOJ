#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int N, dp[1000001][3];

int tiling(int pos, int s){
	int &ret = dp[pos][s];
	if(ret != -1) return ret;
	if(pos == N) return ret = !s;

	if(s == 0){
		ret = (tiling(pos+1, 0) * 2) % MOD;
		if(pos+1 < N){
			ret = (tiling(pos+2, 0) + ret) % MOD;
			ret = (tiling(pos+1, 1) + ret) % MOD;
			ret = (tiling(pos+1, 2) + ret) % MOD;
		}
	}
	else if(s == 1){
		ret = tiling(pos+1, 0);
		if(pos+1 < N) ret = (tiling(pos+1, 2) + ret) % MOD;
	}
	else{
		ret = tiling(pos+1, 0);
		if(pos+1 < N) ret = (tiling(pos+1, 1) + ret) % MOD;
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tiling(0, 0));
}