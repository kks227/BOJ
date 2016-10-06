#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[1000], dp[1000][1000][2];

int card(int l, int r, bool turn){
	int &ret = dp[l][r][turn];
	if(ret != -1) return ret;
	if(l == r) return ret = (turn ? val[l] : 0);

	if(turn)
		return ret = max(card(l+1, r, false)+val[l], card(l, r-1, false)+val[r]);
	return ret = min(card(l+1, r, true), card(l, r-1, true));
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", val+i);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", card(0, N-1, true));
	}
}