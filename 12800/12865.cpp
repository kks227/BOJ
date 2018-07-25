#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, W[100], V[100], dp[101][100001];

int knapsack(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = knapsack(pos+1, k);
	if(k+W[pos] <= K) ret = max(knapsack(pos+1, k+W[pos]) + V[pos], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d %d", W+i, V+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", knapsack(0, 0));
}