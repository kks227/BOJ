#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[10001], f[8];

int ones(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 1) return ret = 1;
	
	ret = 10001;
	for(int i=2; i<8; i++)
		if(f[i] == n) ret = min(ret, ones(i));
	for(int i=1; i<=n/2; i++)
		ret = min(ret, ones(i) + ones(n-i));
	for(int i=2; i<=sqrt(n)+1; i++)
		if(n%i == 0) ret = min(ret, ones(i) + ones(n/i));
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	f[1] = 1;
	for(int i=2; i<8; i++)
		f[i] = f[i-1] * i;
	printf("%d\n", ones(N));
}