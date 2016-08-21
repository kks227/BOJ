#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int N, cost[1000][3], dp[1001][4];

int RGB(int pos, int prev=3){
	int& ret = dp[pos][prev];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = INF;
	for(int i=0; i<3; i++)
		if(prev != i) ret = min(ret, RGB(pos+1, i) + cost[pos][i]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &cost[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", RGB(0));
}