#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int dp[5001][2601];

int p(int n, int k){
	int &ret = dp[n][k];
	if(ret != -1) return ret;
	if(n == 0) return ret = !k;
	if(n < k) return ret = 0;

	ret = p(n-1, k+1);
	if(k > 0) ret += p(n-1, k-1);
	return ret %= MOD;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int L;
		scanf("%d", &L);
		if(L%2) puts("0");
		else printf("%d\n", p(L, 0));
	}
}