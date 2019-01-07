#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 400;
const int M = MAX_N*2 + 1;
const int MAX = MAX_N + M*2;

inline int getVal(int A[MAX][MAX], int r, int c){
	return (r < 0 || r >= MAX || c < 0 || c >= MAX) ? 0 : A[r][c];
}

int main(){
	int N, K, map[MAX][MAX] = {0,}, pSum[MAX][MAX] = {0,}, pSum2[MAX][MAX] = {0,};
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &map[M+i][M+j]);
	for(int i = 0; i < MAX; ++i){
		for(int j = 0; j < MAX; ++j){
			pSum[i][j] = getVal(pSum, i-1, j-1) + getVal(pSum, i-1, j+1) - getVal(pSum, i-2, j) + getVal(map, i-1, j) + map[i][j];
			pSum2[i][j] = getVal(pSum2, i-1, j-1) + getVal(pSum2, i-1, j+1) - getVal(pSum2, i-2, j) + getVal(map, i, j-1) + map[i][j];
		}
	}

	int result = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int temp = getVal(pSum, M+i+K, M+j) + getVal(pSum, M+i-K-1, M+j);
			temp -= getVal(pSum2, M+i-1, M+j-K) + getVal(pSum2, M+i-1, M+j+K+1);
			result = max(temp, result);
		}
	}
	printf("%d\n", result);
}