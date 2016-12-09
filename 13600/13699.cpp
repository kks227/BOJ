#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[36];

long long t(int n){
	long long &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 1;
	
	ret = 0;
	for(int i=0; i<n; i++)
		ret += t(i) * t(n-i-1);
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	fill(dp, dp+36, -1);
	printf("%lld\n", t(N));
}