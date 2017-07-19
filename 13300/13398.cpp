#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[100000], dp[100000][2];

int subsum(int e, int k){
	int &ret = dp[e][k];
	if(ret != -1) return ret;
	if(e == 0) return ret = A[e];
	ret = max(A[e], subsum(e-1, k)+A[e]);
	if(e > 1 && k == 0) ret = max(ret, subsum(e-2, k+1)+A[e]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	int result = A[0];
	for(int i=0; i<N; i++)
		result = max(result, subsum(i, 0));
	printf("%d\n", result);
}