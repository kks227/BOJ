#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = -1e9;

int N, K, t[2][100], c[2][100], dp[101][100001];

int travel(int n, int k){
	int &ret = dp[n][k];
	if(ret != -1) return ret;
	if(n == N) return ret = 0;

	ret = IMPOSSIBLE;
	for(int i=0; i<2; i++)
		if(k >= t[i][n]) ret = max(travel(n+1, k-t[i][n]) + c[i][n], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d %d %d %d", &t[0][i], &c[0][i], &t[1][i], &c[1][i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", travel(0, K));
}