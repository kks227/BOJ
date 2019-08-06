#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 34;

int N, map[MAX][MAX];
long long dp[MAX][MAX];

long long path(int y, int x){
	long long &ret = dp[y][x];
	if(ret != -1) return ret;
	if(y == N-1 && x == N-1) return ret=1;

	ret = 0;
	if(y + map[y][x] < N) ret += path(y + map[y][x], x);
	if(x + map[y][x] < N) ret += path(y, x + map[y][x]);
	return ret;
}

int main(){
	while(1){
		scanf("%d", &N);
		if(N < 0) break;

		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				scanf("%1d", &map[i][j]);
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", path(0, 0));
	}
}