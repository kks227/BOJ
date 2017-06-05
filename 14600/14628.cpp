#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, M, K, X[100], Y[100], dp[101][101];

int art(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(n == N) return ret = (m ? INF : 0);

	ret = art(n+1, m);
	for(int i=1; Y[n]*i <= m; i++)
		ret = min(ret, art(n+1, m-Y[n]*i) + X[n]*i + K*i*(i-1)/2);
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++)
		scanf("%d %d", X+i, Y+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", art(0, M));
}