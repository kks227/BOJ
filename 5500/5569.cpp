#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 100000;

int W, H, dp[101][101][2][2];

int path(int r, int c, bool prev, bool cur){
	if(r==H-1 && c==W-1) return 1;
	int &ret = dp[r][c][prev][cur];
	if(ret != -1) return ret;

	ret = 0;
	if(r<H-1 && !(prev && !cur)) ret += path(r+1, c, (r||c)?cur:true, true);
	if(c<W-1 && !(!prev && cur)) ret += path(r, c+1, (r||c)?cur:false, false);
	return ret %= MOD;
}

int main(){
	scanf("%d %d", &W, &H);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", path(0, 0, 0, 0));
}