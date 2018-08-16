#include <cstdio>
#include <cstring>
using namespace std;

int dp[10001][4];

int add(int n, int k){
	int &ret = dp[n][k];
	if(ret != -1) return ret;
	if(k == 1) return ret = 1;
	
	ret = add(n, k-1);
	if(n >= k) ret += add(n-k, k);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d\n", add(N, 3));
	}
}