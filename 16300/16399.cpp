#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e18;

int C, E, N, S[1001], P[1001];
long long dp[1002][501];

long long drive(int pos, int oil){
	long long &ret = dp[pos][oil];
	if(ret != -1) return ret;
	if(pos == N+1) return ret = 0;

	ret = IMPOSSIBLE;
	for(int i = 0; oil+i <= C; ++i){
		if(oil+i < S[pos]*E) continue;
		ret = min(drive(pos+1, oil+i-S[pos]*E) + i*P[pos], ret);
	}
	return ret;
}

int main(){
	int D, sum = 0;
	scanf("%d %d %d %d", &C, &E, &D, &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", S+i);
		sum += S[i];
	}
	S[N] = D - sum;
	for(int i = 0; i < N; ++i)
		scanf("%d", P+i+1);
	memset(dp, -1, sizeof(dp));
	long long result = drive(0, 0);
	if(result == IMPOSSIBLE) puts("-1");
	else printf("%lld\n", result);
}