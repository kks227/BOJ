#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000007;

int N, M, C, arcade[50][50], dp[50][50][51][51];

int cntPath(int r, int c, int remain, int recent){
	int &ret = dp[r][c][remain][recent];
	if(ret != -1) return ret;

	if(r==N-1 && c==M-1){
		if(arcade[r][c] != 0) return ret = (remain==1 && arcade[r][c]>recent);
		else return ret = (remain==0);
	}
	if(arcade[r][c]){
		if(remain==0 || arcade[r][c]<recent) return ret = 0;
		remain--;
		recent = arcade[r][c];
	}
	ret = 0;
	if(r < N-1) ret += cntPath(r+1, c, remain, recent);
	if(c < M-1) ret += cntPath(r, c+1, remain, recent);
	return ret %= MOD;
}

int main(){
	scanf("%d %d %d", &N, &M, &C);
	for(int i=0; i<C; i++){
		int ar, ac;
		scanf("%d %d", &ar, &ac);
		arcade[ar-1][ac-1] = i+1;
	}
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<=C; i++)
		printf("%d ", cntPath(0, 0, i, 0));
}