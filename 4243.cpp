#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
long long rSum[100], dp[102][102][2];

long long minWait(int l, int r, bool onRight){
	long long &ret = dp[l][r][onRight];
	if(ret != -1) return ret;
	if(l==0 && r==N+1) return ret = 0;

	ret = 1000000000000000000LL;
	if(l > 0) ret = min(ret, minWait(l-1, r, false) + (rSum[onRight?r-2:l]-rSum[l-1]) * (N+l-r+1));
	if(r <= N) ret = min(ret, minWait(l, r+1, true) + (rSum[r-1]-rSum[onRight?r-2:l]) * (N+l-r+1));
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int S;
		scanf("%d %d", &N, &S);
		rSum[0] = 0;
		for(int i=0; i<N-1; i++){
			int dist;
			scanf("%d", &dist);
			rSum[i+1] = rSum[i] + dist;
		}
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", minWait(S-1, S+1, false));
	}
}