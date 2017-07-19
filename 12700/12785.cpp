#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000007;

int R, C, tr, tc, dp[201][201][2];

int toast(int r, int c, bool ate){
	int &ret = dp[r][c][ate];
	if(ret != -1) return ret;
	if(tr == r && tc == c) ate = true;
	if(r == R && c == C) return ret = ate;

	ret = 0;
	if(r < R) ret += toast(r+1, c, ate);
	if(c < C) ret += toast(r, c+1, ate);
	return ret %= MOD;
}

int main(){
	scanf("%d %d %d %d", &C, &R, &tc, &tr);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", toast(1, 1, false));
}