#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 300;
const int INF = 1e9;

int R, C, map[MAX][MAX], dp[MAX][MAX];

int booster(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	if(r == R-1 && c == C-1) return ret = 0;

	ret = INF;
	for(int k = 1; k <= map[r][c]; ++k){
		if(r+k < R) ret = min(booster(r+k, c) + 1, ret);
		if(c+k < C) ret = min(booster(r, c+k) + 1, ret);
	}
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &map[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", booster(0, 0));
}