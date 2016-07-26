#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[1000], dp[1000];

int largestSS(int pos){
	if(pos == N) return 0;
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=pos+1; i<N; i++)
		if(A[i] > A[pos]) ret = max(ret, largestSS(i));
	return ret += A[pos];
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, largestSS(i));
	printf("%d\n", result);
}