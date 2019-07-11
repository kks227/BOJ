#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000001;

long long dp[MAX];

long long bs(int n){
	long long &ret = dp[n];
	if(ret != -1) return ret;
	if(n <= 1) return ret = n;
	int m = n/2;
	return ret = bs(m) + bs(n-m-1) + n;
}

int main(){
	int N;
	fill(dp, dp+MAX, -1);
	for(int t = 1; scanf("%d", &N) > 0; ++t)
		printf("Case %d: %lld\n", t, bs(N));
}