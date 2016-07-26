#include <cstdio>
#include <cstring>
using namespace std;

int N, L, R;
long long dp[21][21][21];

long long cntBuilding(int n, int l, int r){
	long long &ret = dp[n][l][r];
	if(ret != -1) return ret;
	if(n == 1) return (l==1 && r==1);
	
	ret = cntBuilding(n-1, l, r) * (n-2);
	if(L > 1) ret = (ret + cntBuilding(n-1, l-1, r));
	if(R > 1) ret = (ret + cntBuilding(n-1, l, r-1));
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		scanf("%d %d %d", &N, &L, &R);
		printf("%lld\n", cntBuilding(N, L, R));
	}
}