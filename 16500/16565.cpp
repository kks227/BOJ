#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 10007;

int dp[14][53][2];

int poker(int pos, int n, bool satisfied){
	int &ret = dp[pos][n][satisfied];
	if(ret != -1) return ret;
	if(pos == 13) return ret = (satisfied && n == 0);

	ret = poker(pos+1, n, satisfied);
	if(n >= 4) ret += poker(pos+1, n-4, true);
	if(n >= 3) ret += poker(pos+1, n-3, satisfied)*4;
	if(n >= 2) ret += poker(pos+1, n-2, satisfied)*6;
	if(n >= 1) ret += poker(pos+1, n-1, satisfied)*4;
	return ret %= MOD;
}

int main(){
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", poker(0, N, false));
}