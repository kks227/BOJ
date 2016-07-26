#include <cstdio>
#include <cstring>
using namespace std;

// oooo xxoo xoox oxxo
int dp[25][4];

int tiling(int pos, int status){
	if(pos == 0) return !status;
	int &ret = dp[pos][status];
	if(ret != -1) return ret;

	if(status == 0)
		return ret = tiling(pos-1, 0) + tiling(pos-2, 0) + tiling(pos-1, 1)*2 + tiling(pos-1, 2);
	if(status == 1)
		return ret = tiling(pos-1, 0) + tiling(pos-1, 1);
	if(status == 2)
		return ret = tiling(pos-1, 0) + tiling(pos-1, 3);
	return ret = tiling(pos-1, 2);
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d\n", tiling(N, 0));
	}
}