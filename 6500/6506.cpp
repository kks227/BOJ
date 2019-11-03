#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100;

int N, A[MAX];
long long dp[MAX][MAX];

long long kIS(int pos, int k){
	long long &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = 1;
	ret = 0;
	for(int i = pos+1; i < N; ++i)
		if(A[pos] < A[i]) ret += kIS(i, k-1);
	return ret;
}

int main(){
	while(1){
		int K;
		scanf("%d %d", &N, &K);
		if(N == 0) break;
		for(int i = 0; i < N; ++i)
			scanf("%d", A+i);
		memset(dp, -1, sizeof(dp));
		long long result = 0;
		for(int i = 0; i < N; ++i)
			result += kIS(i, K-1);
		printf("%lld\n", result);
	}
}