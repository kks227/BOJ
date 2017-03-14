#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int main(){
	int N, dp[500][500] = {0};
	char map[500][500];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			map[i][j] = getchar();
		dp[i][i] = 1;
	}
	for(int i=N-2; i>=0; i--){
		for(int j=0; j<=i; j++){
			for(int k=0; k<=i; k++){
				if(map[i-j][j] == map[N-1-k][N-1-(i-k)])
					dp[j][k] = (0LL + dp[j][k] + dp[j+1][k] + dp[j][k+1] + dp[j+1][k+1]) % MOD;
				else dp[j][k] = 0;
			}
		}
	}
	printf("%d\n", dp[0][0]);
}