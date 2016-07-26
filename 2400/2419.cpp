#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, x[301], dp[301][301][2];

int minPanelty(int l, int r, int remain, bool onRight){
	if(remain == 0) return 0;
	int &ret = dp[l][r][onRight];
	if(ret != -1) return ret;

	ret = 1000000000;
	if(onRight){
		if(l > 0) ret = min(ret, minPanelty(l-1, r, remain-1, false) + remain*(x[r]-x[l-1]));
		if(r < N-1) ret = min(ret, minPanelty(l, r+1, remain-1, true) + remain*(x[r+1]-x[r]));
	}
	else{
		if(l > 0) ret = min(ret, minPanelty(l-1, r, remain-1, false) + remain*(x[l]-x[l-1]));
		if(r < N-1) ret = min(ret, minPanelty(l, r+1, remain-1, true) + remain*(x[r+1]-x[l]));
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	bool exist0 = false;
	for(int i=0; i<N; i++){
		scanf("%d", x+i);
		if(x[i] == 0) exist0 = true;
	}
	if(!exist0) x[N++] = 0;
	sort(x, x+N);

	int result = 0, start = lower_bound(x, x+N, 0) - x;
	for(int i=1; i<=N-1; i++){
		memset(dp, -1, sizeof(dp));
		result = max(result, i*M - minPanelty(start, start, i, false));
	}
	if(exist0) result += M;
	printf("%d\n", result);
}