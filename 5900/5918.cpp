#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5000;
const int MAX_M = 100000;
const long long INF = 1e18;

int N, M, X[MAX], C[MAX_M], pMin[MAX_M];
long long dp[MAX+1];

long long umbrella(int pos){
	long long &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;
	ret = INF;
	for(int i = pos; i < N; ++i)
		ret = min(umbrella(i+1) + pMin[X[i]-X[pos]], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", X+i);
	sort(X, X+N);
	for(int i = 0; i < M; ++i)
		scanf("%d", C+i);
	pMin[M-1] = C[M-1];
	for(int i = M-2; i >= 0; --i)
		pMin[i] = min(pMin[i+1], C[i]);
	fill(dp, dp+N+1, -1);
	printf("%lld\n", umbrella(0));
}