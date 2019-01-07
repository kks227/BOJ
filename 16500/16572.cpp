#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2002;

inline int getVal(int A[MAX][MAX], int r, int c){
	return (r < 0 || r >= MAX || c < 0 || c >= MAX) ? 0 : A[r][c];
}

inline int read(){
	int result = 0;
	bool start = true;
	while(true){
		char c = getchar();
		if(c < '0' || c > '9'){
			if(start) continue;
			break;
		}
		start = false;
		result = result*10 + c-'0';
	}
	return result;
}

int main(){
	int N = read(), map[2][MAX][MAX] = {0,}, pSum[2][MAX][MAX] = {0,}, result = 0;
	for(int i = 0; i < N; ++i){
		int r = read(), c = read(), k = read();
		++map[1][r+k-1][c];
		--map[1][r-1][c+k];
		--map[0][r-1][c+k-1];
		++map[0][r-1][c-1];
	}
	for(int i = MAX-1; i >= 0; --i){
		for(int j = MAX-1; j >= 0; --j){
			pSum[0][i][j] = getVal(pSum[0], i+1, j) + getVal(pSum[0], i, j+1) - getVal(pSum[0], i+1, j+1) + map[0][i][j];
			pSum[1][i][j] = getVal(pSum[1], i+1, j-1) + getVal(pSum[1], i+1, j) - getVal(pSum[1], i+2, j-1) + map[1][i][j];
			if(pSum[0][i][j] + pSum[1][i][j] > 0) ++result;
		}
	}
	printf("%d\n", result);
}