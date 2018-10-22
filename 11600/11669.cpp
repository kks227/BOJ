#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const long long INF = 1e18;

int N, R, P;
unordered_map<int, long long> dp;

long long debug(int n){
	if(dp.find(n) != dp.end()) return dp[n];
	long long ret = INF;
	for(int i = 1; i < n; ++i)
		ret = min(debug( n/(i+1) + !!(n%(i+1)) ) + 1LL*i*P + R, ret);
	return dp[n] = ret;
}

int main(){
	scanf("%d %d %d", &N, &R, &P);
	dp[1] = 0;
	printf("%lld\n", debug(N));
}