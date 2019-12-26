#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 25;

int N, A[MAX][MAX], dp[MAX][MAX];

int pinball(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	if(r == N-1) return ret = A[r][c];
	return ret = max(pinball(r+1, c), pinball(r+1, c+1)) + A[r][c];
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < i+1; ++j)
			scanf("%d", &A[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", pinball(0, 0));
}