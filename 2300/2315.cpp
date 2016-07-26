#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, D[1000], W[1000], dSum[1001], wSum[1001], cache[1000][1000][2];

int minWaste(int L, int R, bool onRight){
	int &ret = cache[L][R][onRight];
	if(ret != -1) return ret;
	if(L==0 && R==0) return ret = 0;
	ret = 0x7FFFFFFF;
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
	memset(cache, -1, sizeof(cache));
	printf("%d\n", minWaste(M-1, N-M, false));
}