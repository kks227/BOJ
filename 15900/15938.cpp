#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
using namespace std;
const int MOD = 1000000007;
const int xoff[4] = {-1, 1, 0, 0};
const int yoff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int N, Xs, Ys, Xh, Yh, T, dp[401][401][201];
set<P> S;

int hot(int dx, int dy, int t){
	int &ret = dp[dx][dy][t];
	if(ret != -1) return ret;
	if(Xh == Xs+dx-200 && Yh == Ys+dy-200) return ret = 1;
	if(t == 0) return ret = 0;

	ret = 0;
	for(int d=0; d<4; d++){
		int nx = dx + xoff[d], ny = dy + yoff[d];
		if(S.find(P(Xs+nx-200, Ys+ny-200)) == S.end()) ret = (hot(nx, ny, t-1) + ret) % MOD;
	}
	return ret;
}

int main(){
	scanf("%d %d %d %d %d %d", &Xs, &Ys, &T, &Xh, &Yh, &N);
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		S.insert(P(x, y));
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", hot(200, 200, T));
}