#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000001;

int N, M, K;
long long dp[101][101][101];

long long rook(int r, int c, int k){
	long long &ret = dp[r][c][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = 1;
	if(r == 0 || c == 0) return ret = 0;

	ret = rook(r-1, c, k) + rook(r-1, c-1, k-1) * c;
	if(k >= 2){
		if(c >= 2) ret += rook(r-1, c-2, k-2) * c*(c-1)/2;
		if(r >= 2) ret += rook(r-2, c-1, k-2) * c*(r-1);
	}
	return ret %= MOD;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", rook(N, M, K));
}