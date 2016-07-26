#include <cstdio>
#include <cstring>
using namespace std;

int N, M, K, dp[11][221][221];

int sequence(int n, int m, int prev){
	int &ret = dp[n][m][prev];
	if(ret != -1) return ret;
	if(n == 1) return ret = 1;

	ret = 0;
	for(int i=prev; n*i<=m; i++)
		ret += sequence(n-1, m-i, i);
	return ret;
}

void skip(int n, int m, int prev, int k){
	if(n == 1){
		printf("%d\n", m);
		return;
	}

	int pivot = 0;
	for(int i=prev; ; i++){
		if(pivot + sequence(n-1, m-i, i) > k){
			printf("%d ", i);
			skip(n-1, m-i, i, k-pivot);
			return;
		}
		pivot += sequence(n-1, m-i, i);
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	memset(dp, -1, sizeof(dp));
	skip(N, M, 1, K-1);
}