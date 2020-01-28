#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 32;

int N, A[MAX][MAX];
long long dp[MAX][MAX][3];

long long pipe(int r, int c, int d){
	long long &ret = dp[r][c][d];
	if(ret != -1) return ret;
	if(r == N-1 && c == N-1) return ret = 1;

	ret = 0;
	if(d != 1 && c < N-1 && !A[r][c+1])
		ret += pipe(r, c+1, 0);
	if(d != 0 && r < N-1 && !A[r+1][c])
		ret += pipe(r+1, c, 1);
	if(r < N-1 && c < N-1 && !A[r][c+1] && !A[r+1][c] && !A[r+1][c+1])
		ret += pipe(r+1, c+1, 2);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &A[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", pipe(0, 1, 0));
}