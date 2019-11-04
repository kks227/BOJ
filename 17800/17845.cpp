#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 10000;
const int MAX_K = 1000;

int N, K, I[MAX_K], T[MAX_K], dp[MAX_K+1][MAX_N+1];

int knapsack(int pos, int v){
	int &ret = dp[pos][v];
	if(ret != -1) return ret;
	if(pos == K) return ret = 0;

	ret = knapsack(pos+1, v);
	if(v >= T[pos]) ret = max(knapsack(pos+1, v-T[pos]) + I[pos], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < K; ++i)
		scanf("%d %d", I+i, T+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", knapsack(0, N));
}