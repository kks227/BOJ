#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2000;

int N, A[MAX], dp[2][MAX];

int LIS(int pos){
	int &ret = dp[0][pos];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = pos+1; i < N; ++i)
		if(A[pos] < A[i]) ret = max(LIS(i) + 1, ret);
	return ret;
}

int LDS(int pos){
	int &ret = dp[1][pos];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = pos+1; i < N; ++i)
		if(A[pos] > A[i]) ret = max(LDS(i) + 1, ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	fill(dp[0], dp[0]+MAX, -1);
	fill(dp[1], dp[1]+MAX, -1);
	int result = 0;
	for(int i = 0; i < N; ++i)
		result = max(LIS(i) + LDS(i) + 1, result);
	printf("%d\n", result);
}