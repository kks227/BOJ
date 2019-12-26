#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 350;
const int MAX_D = 100000;
const int INF = 1e9;

int main(){
	int N, D, L[MAX], C[MAX], dp[MAX_D+1];
	scanf("%d %d", &D, &N);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", L+i, C+i);
	fill(dp, dp+D+1, 0);
	dp[0] = INF;
	for(int i = 0; i < N; ++i){
		for(int j = D; j >= 0; --j){
			int k = j + L[i];
			if(k > D) continue;
			dp[k] = max(min(dp[j], C[i]), dp[k]);
		}
	}
	printf("%d\n", dp[D]);
}