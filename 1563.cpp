#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000;

int N, dp[1000][2][3];

int pa(int cur, int late, int absent){
	if(cur == N) return 1;
	int &ret = dp[cur][late][absent];
	if(ret != -1) return ret;

	ret = pa(cur+1, late, 0);
	if(late == 0) ret += pa(cur+1, 1, 0);
	if(absent < 2) ret += pa(cur+1, late, absent+1);
	return ret %= MOD;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", pa(0, 0, 0));
}