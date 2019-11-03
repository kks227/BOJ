#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2000;
const int INF = 1e9 * 2 + 1;

int N, M, R, D, H[MAX], T[MAX], E[MAX][2], dp[MAX];

int building(int k){
	int &ret = dp[k];
	if(ret != -1) return ret;
	if(k == D) return ret = 0;

	ret = INF;
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < 2; ++j){
			if(k - E[i][j] + H[i] > N || k - E[i][j] < 0) continue;
			ret = min(building(k - E[i][j] + E[i][!j]) + T[i], ret);
		}
	}
	return ret;
}

int main(){
	scanf("%d %d %d %d", &N, &R, &D, &M);
	--R; --D;
	for(int i = 0; i < M; ++i){
		scanf("%d %d %d %d", H+i, T+i, &E[i][0], &E[i][1]);
		--E[i][0]; --E[i][1];
	}
	fill(dp, dp+N, -1);
	int result = building(R);
	if(result == INF) result = -1;
	printf("%d\n", result);
}