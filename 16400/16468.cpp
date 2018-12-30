#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 100030001;

int dp[301][301][2];

int makeTree(int n, int h, bool need){
	int &ret = dp[n][h][need];
	if(ret != -1) return ret;
	if(h == 0) return ret = !n;
	if(n == 0) return ret = !need;

	ret = 0;
	for(int i = 0; i < n; ++i){
		long long temp = 0;
		if(need){
			temp += 1LL * makeTree(i, h-1, true) * makeTree(n-1-i, h-1, false);
			temp += 1LL * makeTree(i, h-1, false) * makeTree(n-1-i, h-1, true);
			temp -= 1LL * makeTree(i, h-1, true) * makeTree(n-1-i, h-1, true);
		}
		else temp = 1LL * makeTree(i, h-1, false) * makeTree(n-1-i, h-1, false);
		ret = (ret + temp) % MOD;
	}
	return ret;
}

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", makeTree(N, L, true));
}