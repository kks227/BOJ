#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, C[2000], pSum[2001] = {0}, dp[2000][2001] = {0};
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", C+(N-i-1));
	for(int i = 0; i < N; i++)
		pSum[i+1] = pSum[i] + C[i];

	fill(dp[0], dp[0]+N+1, C[0]);
	for(int i = 1; i < N; i++){
		for(int j = 1; j <= N; j++){
			dp[i][j] = dp[i][j-1];
			if(i <= j*2-1) dp[i][j] = max(pSum[i+1], dp[i][j]);
			else{
				dp[i][j] = max(pSum[i+1] - dp[i-(j*2-1)][j*2-1], dp[i][j]);
				if(i >= j*2) dp[i][j] = max(pSum[i+1] - dp[i-j*2][j*2], dp[i][j]);
			}
		}
	}
	printf("%d\n", dp[N-1][1]);
}