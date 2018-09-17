#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, A[1000][1003], dp1[1000][1004], dp2[1001][1002];

int silver1(int r, int c){
	int &ret = dp1[r][c];
	if(ret != -1) return ret;
	if(c > C) return ret = 0;

	ret = silver1(r, c+2) + A[r][c+1];
	if(r > 0) ret = max(silver1(r-1, c+1), ret);
	if(r < R-1) ret = max(silver1(r+1, c+1), ret);
	return ret += A[r][c];
}

int silver2(int r, int c){
	int &ret = dp2[r][c];
	if(ret != -1) return ret;
	if(c == C) return ret = 0;

	ret = 0;
	if(r > 0) ret = max(silver2(r-1, c+1) + A[r-1][c+1], ret);
	if(r < R) ret = max(silver2(r+1, c+1) + A[r][c+1], ret);
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &A[i][j+1]);
	C++;
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	int result = silver2(R, 0);
	for(int i=0; i<R; i++){
		for(int j=0; j<2; j++)
			result = max(silver1(i, j), result);
		result = max(silver2(i, 0), result);
	}
	printf("%d\n", result);
}