#include <cstdio>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

int c[2049][2049], dp[11];

int C(int n, int r){
	int &ret = c[n][r];
	if(ret) return ret;
	if(r == 0 || r == n) return ret = 1;
	return ret = (C(n-1, r-1) + C(n-1, r)) % MOD;
}

int numbering(int h){
	int &ret = dp[h];
	if(ret != -1) return ret;
	if(h == 0) return ret = 1;
	return ret = (1LL*numbering(h-1)*numbering(h-1))%MOD*C((1<<h+1)-2, (1<<h)-1)%MOD;
}

int main(){
	int H;
	scanf("%d", &H);
	fill(dp, dp+11, -1);
	printf("%d\n", numbering(H));
}