#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 500000;
const long long INF = 1e18;

int main(){
	int N, M, score[MAX_N], bonus[MAX_N];
	long long pSum[MAX_N+1] = {0}, dp1[MAX_N], dp2[MAX_N];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", score+i);
		pSum[i+1] = pSum[i] + score[i];
	}
	for(int i=0; i<N; i++)
		scanf("%d", bonus+i);
	fill(dp1, dp1+MAX_N, -INF);
	for(int i=0; i<N; i++){
		dp1[i] = (i>0 ? dp2[i-1] : 0) - score[i];
		if(i >= M-1)
			dp1[i] = max((i>=M ? dp1[i-M] : 0) + pSum[i+1] - pSum[i+1-M] + bonus[i], dp1[i]);
		dp2[i] = max((i>0 ? dp2[i-1] : 0) + score[i], dp1[i]);
	}
	printf("%lld\n", dp2[N-1]);
}