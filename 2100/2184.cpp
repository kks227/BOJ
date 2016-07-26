#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, x[1001], dp[1001][1001][2];

int minSpoil(int l, int r, int remain, bool onRight){
	if(remain == 0) return 0;
	int &ret = dp[l][r][onRight];
	if(ret != -1) return ret;

	ret = 1000000000;
	if(onRight){
		if(l > 0) ret = min(ret, minSpoil(l-1, r, remain-1, false) + remain*(x[r]-x[l-1]));
		if(r < N-1) ret = min(ret, minSpoil(l, r+1, remain-1, true) + remain*(x[r+1]-x[r]));
	}
	else{
		if(l > 0) ret = min(ret, minSpoil(l-1, r, remain-1, false) + remain*(x[l]-x[l-1]));
		if(r < N-1) ret = min(ret, minSpoil(l, r+1, remain-1, true) + remain*(x[r+1]-x[l]));
	}
	return ret;
}

int main(){
	int L;
	scanf("%d %d", &N, &L);
	bool existL = false;
	for(int i=0; i<N; i++){
		scanf("%d", x+i);
		if(x[i] == L) existL = true;
	}
	if(!existL) x[N++] = L;
	sort(x, x+N);

	int start = lower_bound(x, x+N, L) - x;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minSpoil(start, start, N-1, false));
}