#include <cstdio>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int pSum[1001][1001];

inline int rangeSum(int x1, int y1, int x2, int y2){
	return pSum[x2][y2] - pSum[x2][y1] - pSum[x1][y2] + pSum[x1][y1];
}

int main(){
	int N, x[1000], y[1000], X = 0, Y = 0;
	unordered_map<int, int> xHash, yHash;
	set<int> xSet, ySet;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", x+i, y+i);
		xSet.insert(x[i]);
		ySet.insert(y[i]);
	}
	for(int x: xSet)
		xHash[x] = X++;
	for(int y: ySet)
		yHash[y] = Y++;
	int A[1000][1000] = {0,};
	for(int i = 0; i < N; ++i)
		++A[xHash[x[i]]][yHash[y[i]]];
	for(int i = 0; i < X; ++i)
		for(int j = 0; j < Y; ++j)
			pSum[i+1][j+1] = pSum[i+1][j] + pSum[i][j+1] - pSum[i][j] + A[i][j];

	int result = N;
	for(int i = 0; i <= X; ++i){
		for(int j = 0; j <= Y; ++j){
			int temp = max(rangeSum(0, 0, i, j), rangeSum(i, j, X, Y));
			temp = max(rangeSum(0, j, i, Y), temp);
			temp = max(rangeSum(i, 0, X, j), temp);
			result = min(temp, result);
		}
	}
	printf("%d\n", result);
}