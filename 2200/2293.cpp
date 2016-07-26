#include <cstdio>
using namespace std;

int main(){
	int N, K, dp[10001] = {1};
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int cost;
		scanf("%d", &cost);
		for(int j=cost; j<=K; j++)
			dp[j] += dp[j-cost];
	}
	printf("%d\n", dp[K]);
}