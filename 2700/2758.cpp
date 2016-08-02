#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
long long dp[11][2001];

long long lotto(int n, int m){
	long long &ret = dp[n][m];
	if(ret != -1) return ret;
	if(m == 0) return ret = 0;
	if(n == 0) return ret = 1;

	ret = 0;
	for(int i=m/2; i>0; i--) ret += lotto(n-1, i);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		scanf("%d %d", &N, &M);
		long long result = 0;
		for(int i=M; i>=(1<<N-1); i--)
			result += lotto(N-1, i);
		printf("%lld\n", result);
	}
}