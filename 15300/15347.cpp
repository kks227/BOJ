#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int d[3][1000], N, dp[1001][2];

int eraseCols(int k, int c){
	int &ret = dp[k][c];
	if(ret != -1) return ret;
	if(k == 0) return ret = (c ? INF : 0);

	ret = INF;
	int r = (c + d[0][k-1] + d[1][k-1]) % 10;
	int nc = (c + d[0][k-1] + d[1][k-1]) / 10;
	ret = min(eraseCols(k-1, c)+1, ret);
	if(r == d[2][k-1]) ret = min(eraseCols(k-1, nc), ret);
	return ret;
}

int main(){
	while(1){
		scanf("%d", &N);
		if(N == 0) break;

		for(int i=0; i<3; i++)
			for(int j=0; j<N; j++)
				scanf("%1d", &d[i][j]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", eraseCols(N, 0));
	}
}