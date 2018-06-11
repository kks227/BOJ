#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long INF = 1e18;

int N, X[2000], Y[2000];
long long dp[2000][2000];

inline int d2(int x, int y){ return (X[x]-Y[y])*(X[x]-Y[y]); }

long long wave(int x, int y){
	long long ret = dp[x][y];
	if(ret != -1) return ret;
	if(x == N-1 && y == N-1) return ret = d2(x, y);

	ret = INF;
	if(x < N-1) ret = min(wave(x+1, y), ret);
	if(y < N-1) ret = min(wave(x, y+1), ret);
	if(x < N-1 && y < N-1) ret = min(wave(x+1, y+1), ret);
	return ret += d2(x, y);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", X+i);
	for(int i=0; i<N; i++)
		scanf("%d", Y+i);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", wave(0, 0));
}