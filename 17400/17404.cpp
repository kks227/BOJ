#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int INF = 1e9;

int N, val[MAX][3], dp[MAX+1][3][3];

int rgb(int pos, int c1, int c2){
	int &ret = dp[pos][c1][c2];
	if(ret != -1) return ret;
	if(pos == N) return ret = (N == 1 || c1 != c2 ? 0 : INF);

	ret = INF;
	for(int i = 0; i < 3; ++i)
		if(c1 != i) ret = min(rgb(pos+1, i, c2) + val[pos][i], ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < 3; ++j)
			scanf("%d", &val[i][j]);
	memset(dp, -1, sizeof(dp));
	int result = INF;
	for(int i = 0; i < 3; ++i)
		result = min(rgb(1, i, i) + val[0][i], result);
	printf("%d\n", result);
}