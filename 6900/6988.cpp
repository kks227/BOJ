#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[3000];
long long dp[3000][3000];

long long maxSum(int p, int q){
	long long &ret = dp[p][q];
	if(ret != -1) return ret;

	ret = 0;
	int nextVal = val[q]*2-val[p];
	int r = lower_bound(val+q+1, val+N, nextVal) - val;
	if(r != N && val[r] == nextVal)
		ret = max(0LL+val[q]+val[r], maxSum(q, r)) + val[p];
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	memset(dp, -1, sizeof(dp));
	long long result = 0;
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
			result = max(result, maxSum(i, j));
	printf("%lld\n", result);
}