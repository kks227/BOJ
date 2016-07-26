#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, cost[15][15], dp[15][32768][10];

int exchange(int holder, int had, int mc){
	int &ret = dp[holder][had][mc];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=0; i<N; i++)
		if(i != holder && cost[holder][i] >= mc && !(had & (1<<i)))
			ret = max(ret, exchange(i, had | (1<<i), cost[holder][i]));
	return ++ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%1d", &cost[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", exchange(0, 1, 0));
}