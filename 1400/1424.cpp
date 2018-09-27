#include <cstdio>
#include <algorithm>
using namespace std;

int N, L, C, K, dp[100001];

int album(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return 0;

	ret = album(n-1) + 1;
	for(int i=2; i<=min(K, n) && i*L+i-1<=C; i++)
		if(i%13 != 0) ret = min(album(n-i) + 1, ret);
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &L, &C);
	for(K=1; (K+1)*L+K <= C; K++);
	fill(dp, dp+N+1, -1);
	printf("%d\n", album(N));
}