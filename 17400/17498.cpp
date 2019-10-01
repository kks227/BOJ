#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200000;
const int INF = 1+2*1e9;

int R, C, D, A[MAX], dp[MAX];

int jump(int k){
	int &ret = dp[k];
	if(ret > -INF) return ret;
	int r = k/C, c = k%C;
	if(r == R-1) return ret = 0;

	ret = -INF;
	for(int i = 1; i <= D && r+i < R; ++i){
		int nr = r + i;
		for(int j = 0; i+j <= D; ++j){
			for(int k = -1; k <= 1; k += 2){
				int nc = c + j*k;
				if(nc < 0 || nc >= C) continue;
				ret = max(jump(nr*C+nc) + A[r*C+c]*A[nr*C+nc], ret);
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d %d %d", &R, &C, &D);
	fill(dp, dp+R*C, -INF);
	for(int i = 0; i < R*C; ++i)
		scanf("%d", A+i);
	int result = -INF;
	for(int i = 0; i < C; ++i)
		result = max(jump(i), result);
	printf("%d\n", result);
}