#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500;

long long dp[MAX][MAX];

long long UPD(int n, int m){
	long long &ret = dp[n][m];
	if(ret != -1) return ret;
	if(m == 0) return ret = 1;

	ret = 0;
	for(int i=min(n, m); i>=1; i--)
		ret += UPD(i, m-i);
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		long long result = (N%2 ? 0 : UPD(N, N/2));
		for(int i=0; i<=N/2; i++)
			result += UPD(i*2+N%2, N/2-i);
		printf("%d %lld\n", N, result);
	}
}