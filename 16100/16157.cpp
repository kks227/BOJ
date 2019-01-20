#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100;

int N, C[MAX], dp[MAX+1][MAX+1][3];

int blog(int s, int e, int col){
	int &ret = dp[s][e][col];
	if(ret != -1) return ret;
	if(s >= N || s > e) return ret = 0;
	if(s == e) return ret = (C[s] != col);

	ret = blog(s+1, e, col) + (C[s] != col);
	for(int i = s+1; i <= e; ++i){
		int temp1 = N, temp2 = N;
		for(int c = 0; c < 3; ++c)
			temp1 = min(blog(s, i-1, c) + (c != col), temp1);
		for(int c = 0; c < 3; ++c)
			temp2 = min(blog(i, e, c) + (c != col), temp2);
		ret = min(temp1 + temp2, ret);
	}
	return ret;
}

int main(){
	scanf("%d\n", &N);
	for(int i = 0; i < N; ++i){
		char c = getchar();
		C[i] = (c == 'R' ? 0 : c == 'G' ? 1 : 2);
	}
	memset(dp, -1, sizeof(dp));
	int result = N;
	for(int c = 0; c < 3; ++c)
		result = min(blog(0, N-1, c) + 1, result);
	printf("%d\n", result);
}