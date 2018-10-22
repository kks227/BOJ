#include <cstdio>
#include <algorithm>
using namespace std;
const unsigned int MOD = 1000000009;

int main(){
	int N, M, K, A[1000], B[1000];
	unsigned int dp[10][1000][1000] = {0}, rSum[10][1001][1001] = {0};
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	for(int i = 0; i < M; ++i)
		scanf("%d", B+i);
	sort(A, A+N);
	sort(B, B+M);
	for(int k = 0; k < K; ++k){
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				if(A[i] > B[j]) dp[k][i][j] = k > 0 ? rSum[k-1][i][j] : 1;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < M; ++j)
				rSum[k][i+1][j+1] = (rSum[k][i][j+1] + rSum[k][i+1][j] + MOD - rSum[k][i][j] + dp[k][i][j]) % MOD;
	}
	printf("%u\n", rSum[K-1][N][M]);
}