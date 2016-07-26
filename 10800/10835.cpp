#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[2000], B[2000], dp[2000][2000];

int maxScore(int a, int b){
	if(a==N || b==N) return 0;
	int &ret = dp[a][b];
	if(ret != -1) return ret;

	ret = max(maxScore(a+1, b), maxScore(a+1, b+1));
	if(A[a] > B[b]) ret = max(ret, maxScore(a, b+1)+B[b]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	for(int i=0; i<N; i++)
		scanf("%d", B+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxScore(0, 0));
}