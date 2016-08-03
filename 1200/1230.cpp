#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

char O[1001], N[1001];
int dp[1001][1001][2];

int dist(int o, int n, bool suc=false){
	int &ret = dp[o][n][suc];
	if(ret != -1) return ret;
	if(!O[o]) return ret = (N[n] > 0);
	if(!N[n]) return ret = IMPOSSIBLE;

	ret = min(IMPOSSIBLE, dist(o, n+1, true) + !suc);
	if(O[o] == N[n]) ret = min(ret, dist(o+1, n+1));
	return ret;
}

int main(){
	gets(O);
	gets(N);
	memset(dp, -1, sizeof(dp));
	int result = dist(0, 0);
	if(result == IMPOSSIBLE) puts("-1");
	else printf("%d\n", result);
}