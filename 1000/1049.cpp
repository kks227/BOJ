#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, M, p[50], e[50], dp[51][101];

int minCost(int pos, int remain){
	int &ret = dp[pos][remain];
	if(ret != -1) return ret;
	if(remain == 0) return ret = 0;
	if(pos == M) return ret = IMPOSSIBLE;

	ret = min(minCost(pos, max(remain-6, 0))+p[pos], minCost(pos, remain-1)+e[pos]);
	ret = min(ret, minCost(pos+1, remain));
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++)
		scanf("%d %d", p+i, e+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minCost(0, N));
}