#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000009;

int dp[100001];

int add(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 1;

	ret = 0;
	for(int i=1; i<=3; i++){
		if(n >= i*2) ret = (ret + add(n-i*2)) % MOD;
		if(n == i) ret = (ret + 1) % MOD;
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d\n", add(N));
	}
}