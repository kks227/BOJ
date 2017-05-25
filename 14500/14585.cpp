#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
bool candy[301][301];
long long dp[301][301];

long long sasu(int x, int y){
	long long &ret = dp[x][y];
	if(ret != -1) return ret;

	ret = 0;
	if(x < 300) ret = max(sasu(x+1, y), ret);
	if(y < 300) ret = max(sasu(x, y+1), ret);
	if(candy[x][y]) ret += max(M-x-y, 0);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		candy[x][y] = true;
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", sasu(0, 0));
}