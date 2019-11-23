#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int MAX_M = 10;

int N, M, V[MAX][MAX_M], dp[MAX+1][MAX_M];

int dessert(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;
	ret = 0;
	for(int i = 0; i < M; ++i)
		ret = max(dessert(pos+1, i) + V[pos][i] / (k == i ? 2 : 1), ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &V[j][i]);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i = 0; i < M; ++i)
		result = max(dessert(1, i) + V[0][i], result);
	printf("%d\n", result);
}