#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, W[1000], E[1000];
long long dp[1000][1000];

long long spaceship(int pos, int start, int maxW, int maxE){
	long long &ret = dp[pos][start];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = 1LL*max(maxW, W[pos])*max(maxE, E[pos]);

	ret = min(
		1LL*max(maxW, W[pos])*max(maxE, E[pos]) + spaceship(pos+1, pos+1, W[pos+1], E[pos+1]),
		spaceship(pos+1, start, max(maxW, W[pos]), max(maxE, E[pos]))
	);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", W+i);
	for(int i=0; i<N; i++)
		scanf("%d", E+i);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", spaceship(0, 0, W[0], E[0]));
}