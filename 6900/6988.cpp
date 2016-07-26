#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[3000], dp[3000][3000];

int maxSum(int p, int q){
	int &ret = dp[p][q];
	if(ret != -1) return ret;

	ret = 0;
	int nextVal = val[q]*2-val[p];
	int r = lower_bound(val+q+1, val+N, nextVal) - val;
	if(r != N && val[r] == nextVal)
		ret = max(val[q]+val[r], maxSum(q, r)) + val[p];
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
			result = max(result, maxSum(i, j));
	printf("%d\n", result);
}