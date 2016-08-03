#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[101];

long long kriii(int n){
	long long &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;

	ret = kriii(n-1) + 1;
	if(n > 2){
		for(int i=1; i<=n-2; i++)
			ret = max(ret, kriii(n-2-i)*(i+1));
	}
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", kriii(N));
}