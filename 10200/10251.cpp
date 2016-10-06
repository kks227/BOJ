#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int M, N, L, G, rg[100][99], cg[99][100], dp[100][100][200][2];

int minGasoline(int r, int c, int t, bool d){ // t: turning cnt, d: false(h), true(v)
	int &ret = dp[r][c][t][d];
	if(ret != -1) return ret;
	if(r == 0 && c == 0) return ret = (t == 0 ? 0 : INF);

	ret = INF;
	if(r > 0 && t-!d >= 0) ret = min(ret, minGasoline(r-1, c, t-!d, true) + cg[r-1][c]);
	if(c > 0 && t-d >= 0) ret = min(ret, minGasoline(r, c-1, t-d, false) + rg[r][c-1]);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d %d", &M, &N, &L, &G);
		for(int i=0; i<M; i++)
			for(int j=0; j<N-1; j++)
				scanf("%d", &rg[i][j]);
		for(int i=0; i<M-1; i++)
			for(int j=0; j<N; j++)
				scanf("%d", &cg[i][j]);

		memset(dp, -1, sizeof(dp));
		bool success = false;
		for(int i=0; i<M+N; i++){
			int temp = min(minGasoline(M-1, N-1, i, false), minGasoline(M-1, N-1, i, true));
			if(temp <= G){
				printf("%d\n", (M+N-2)*L+i);
				success = true;
				break;
			}
		}
		if(!success) puts("-1");
	}
}