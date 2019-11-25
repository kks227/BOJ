#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5000;
const int MOD = 1000000007;

int dp[MAX+1];

int btree(int e){
	int &ret = dp[e];
	if(ret != -1) return ret;
	if(e == 0) return ret = 1;
	ret = 2*btree(e-1) % MOD;
	for(int i = 1; i < e; ++i)
		ret = (1LL*btree(i-1)*btree(e-i-1) + ret) % MOD;
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	fill(dp, dp+MAX+1, -1);
	for(int t = 0; t < T; ++t){
		int E;
		scanf("%d", &E);
		printf("%d\n", btree(E));
	}
}