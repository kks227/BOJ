#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500;

int N, K, x[MAX], y[MAX], dp[MAX][MAX];

int marathon(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = 0;

	ret = marathon(pos+1, k) + abs(x[pos+1]-x[pos]) + abs(y[pos+1]-y[pos]);
	for(int i = 1; i <= k && pos+i+1 < N; ++i)
		ret = min(marathon(pos+i+1, k-i) + abs(x[pos+i+1]-x[pos]) + abs(y[pos+i+1]-y[pos]), ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", x+i, y+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", marathon(0, K));
}