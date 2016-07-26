#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, dp[500][1001];
vector<int> val[500];

int maxSum(int n, int prev){
	if(n == N) return 0;
	int &ret = dp[n][prev];
	if(ret != -1) return ret;

	ret = maxSum(n+1, prev);
	for(int v: val[n])
		if(v >= prev)
			ret = max(ret, maxSum(n+1, v)+v);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int M;
		scanf("%d", &M);
		val[i].resize(M);
		for(int j=0; j<M; j++)
			scanf("%d", &val[i][j]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxSum(0, 0));
}