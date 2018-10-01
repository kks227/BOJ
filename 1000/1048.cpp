#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
const int MAX_SIZE = 300;
const int MAX_LEN = 50;
const int INF = 1e9;

int R, C, L, dp[MAX_SIZE][MAX_SIZE][MAX_LEN];
long long pSum[MAX_SIZE+1][MAX_SIZE+1];
char S[MAX_LEN+1], map[MAX_SIZE][MAX_SIZE];

struct Rect{
	int r1, c1, r2, c2;
	Rect(): Rect(0, 0, 0, 0){}
	Rect(int r3, int c3, int r4, int c4): r1(r3), c1(c3), r2(r4), c2(c4){
		if(r1 >= r2 || c1 >= c2) r1 = c1 = r2 = c2 = 0;
	}
};

inline Rect intersection(Rect A, Rect B){
	return Rect(max(A.r1, B.r1), max(A.c1, B.c1), min(A.r2, B.r2), min(A.c2, B.c2));
}

inline long long rangeSum(Rect A){
	Rect B = intersection(A, Rect(0, 0, R, C));
	return (MOD*2 + pSum[B.r2][B.c2] - pSum[B.r1][B.c2] - pSum[B.r2][B.c1] + pSum[B.r1][B.c1]) % MOD;
}

inline int getDPval(int r, int c, int k){
	if(r < 0 || r >= R || c < 0 || c >= C) return 0;
	return dp[r][c][k];
}

int main(){
	scanf("%d %d %d %s\n", &R, &C, &L, S);
	L = strlen(S);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
		getchar();
	}

	for(int k=0; k<L; k++){
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(map[i][j] != S[k]) continue;
				if(k == 0) dp[i][j][0] = 1;
				else{
					long long temp = rangeSum(Rect(-INF, -INF, i-1, j-1)) - getDPval(i-2, j-2, k-1);
					temp += rangeSum(Rect(-INF, j+2, i-1, INF)) - getDPval(i-2, j+2, k-1);
					temp += rangeSum(Rect(i+2, -INF, INF, j-1)) - getDPval(i+2, j-2, k-1);
					temp += rangeSum(Rect(i+2, j+2, INF, INF)) - getDPval(i+2, j+2, k-1);
					dp[i][j][k] = (MOD*4LL + temp) % MOD;
				}
			}
		}

		memset(pSum, 0, sizeof(pSum));
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				pSum[i+1][j+1] = (MOD + pSum[i+1][j] + pSum[i][j+1] + dp[i][j][k] - pSum[i][j]) % MOD;
	}

	int result = 0;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			result = (dp[i][j][L-1] + result) % MOD;
	printf("%d\n", result);
}