#include <cstdio>
#include <cstring>
using namespace std;

int N, K, dp[41][2];

int seat(int n, bool k=false){
	int &ret = dp[n][k];
	if(ret != -1) return ret;
	if(n == 0) return ret = k;

	ret = seat(n-1, k);
	if(n > 1) ret += seat(n-2, k);
	if(!k){
		for(int i=n-1; i>=0; i--)
			ret += seat(i, true) * (i==n-1 ? 1 : 2);
	}
	return ret;
}

int main(){
	int f[41] = {1, 1,};
	scanf("%d %d", &N, &K);
	for(int i=2; i<=40; i++)
		f[i] = f[i-1] + f[i-2];

	int L = K-1, R = N-K;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", f[L]*f[R] + seat(L)*f[R] + f[L]*seat(R));
}