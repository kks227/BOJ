#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000009;

int N, M, dp[3000][3000];
char map[3000][3000];

int gift(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	if(r == N-1 && c == M-1) return ret = 1;

	ret = 0;
	if(map[r][c] == 'E' || map[r][c] == 'B') ret += gift(r, c+1);
	if(map[r][c] == 'S' || map[r][c] == 'B') ret += gift(r+1, c);
	return ret %= MOD;
}

int main(){
	scanf("%d %d\n", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
		getchar();
	}
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			result = (gift(i, j) + result) % MOD;
	printf("%d\n", result);
}