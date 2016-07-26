#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int N, L, R, dp[101][101][101];

int cntBuilding(int n, int l, int r){
	int &ret = dp[n][l][r];
	if(ret != -1) return ret;
	if(n == 1) return (l==1 && r==1);
	
	ret = 1LL * cntBuilding(n-1, l, r) * (n-2) % MOD;
	if(L > 1) ret = (ret + cntBuilding(n-1, l-1, r)) % MOD;
	if(R > 1) ret = (ret + cntBuilding(n-1, l, r-1)) % MOD;
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &L, &R);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cntBuilding(N, L, R));
}