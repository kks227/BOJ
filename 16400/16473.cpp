#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[5000], dp[5001][5001][3];

int maxLen(int s, int e, int status = 0){
	int &ret = dp[s][e][status];
	if(ret != -1) return ret;
	if(s == 0 || e == N) return ret = 0;

	ret = 0;
	if(status == 1){
		if(A[s] == A[e]) ret = max(maxLen(s, e+1) + 2, ret);
		ret = max(maxLen(s, e+1), ret);
	}
	else if(status == 2){
		if(A[s-1] == A[e-1]) ret = max(maxLen(s-1, e) + 2, ret);
		ret = max(maxLen(s-1, e), ret);
	}
	else{
		if(A[s-1] == A[e]) ret = max(maxLen(s-1, e+1) + 2, ret);
		ret = max(maxLen(s, e+1), ret);
		ret = max(maxLen(s-1, e), ret);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int pos;
		scanf("%d", &pos);
		printf("%d\n", N - maxLen(pos-1, pos) - 1);
	}
}