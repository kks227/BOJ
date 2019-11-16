#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100;
const int MOD = 10007;

int N, dp[MAX][MAX][MAX];

int fire(int r, int c1, int c2){
	int &ret = dp[r][c1][c2];
	if(ret != -1) return ret;
	if(r == N-1) return ret = 1;

	ret = 0;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			if(c1+i != c2+j) ret = (fire(r+1, c1+i, c2+j) + ret) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", fire(0, 0, 0));
}