#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long INF = 1e18;

int N, M, D[1000], W[1000];
long long wSum[1001], dp[1000][1000][2];

long long minWaste(int L, int R, bool onRight){
	long long &ret = dp[L][R][onRight];
	if(ret != -1) return ret;
	if(L==0 && R==0) return ret = 0;

	ret = INF;
	if(L) ret = minWaste(L-1, R, false) + (wSum[L]+wSum[N]-wSum[N-R])*(onRight?D[N-R-1]-D[L-1]:D[L]-D[L-1]);
	if(R) ret = min(ret, minWaste(L, R-1, true) + (wSum[L]+wSum[N]-wSum[N-R])*(onRight?D[N-R]-D[N-R-1]:D[N-R]-D[L]));
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	wSum[0] = 0;
	for(int i=0; i<N; i++){
		scanf("%d %d", D+i, W+i);
		wSum[i+1] = wSum[i] + W[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", minWaste(M-1, N-M, false));
}