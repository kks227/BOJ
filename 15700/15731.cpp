#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int main(){
	int N, dp[2][5002] = {0};
	char S[5001];
	scanf("%s", S);
	N = strlen(S);

	dp[0][0] = 1;
	bool p = false;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(S[i] == 'f')
				dp[!p][j+1] = (dp[p][j] + dp[!p][j+1]) % MOD;
			else
				dp[!p][j] = (dp[p][j] + dp[!p][j]) % MOD;
			if(i < N-1) dp[p][j] = 0;
		}
		if(i < N-1) dp[p][N] = 0;

		if(S[i] == 'e'){
			for(int j=N; j>0; j--)
				dp[!p][j-1] = (dp[!p][j] + dp[!p][j-1]) % MOD;
		}
		p = !p;
	}

	int result = 0;
	for(int i=0; i<=N; i++)
		result = (dp[!p][i] + result) % MOD;
	printf("%d\n", result);
}