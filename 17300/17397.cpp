#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int MAX_M = 200;
const int MAX_C = 10;
const int INF = 1e9;

int N, M, C[MAX], dp[MAX+1][MAX_M+1][MAX_C+1];

int flex(int n, int m, int c){
	int &ret = dp[n][m][c];
	if(ret != -1) return ret;
	if(n == N) return ret = 0;

	ret = INF;
	for(int i = 0; i <= m && C[n]+i <= MAX_C; ++i)
		ret = min(flex(n+1, m-i, C[n]+i) + (int)pow(max(c-C[n]-i, 0), 2), ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", C+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", flex(0, M, 0));
}