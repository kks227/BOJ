#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[2][1000], dp[1001][1001];

int trash(int a, int b){
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	if(a == N || b == N) return ret = 0;

	ret = 1;
	for(int i=a+1; i<N; i++){
		if(A[0][a] >= A[0][i]) continue;
		for(int j=b+1; j<N; j++){
			if(A[0][i] == A[1][j]){
				ret = max(ret, trash(i, j)+1);
				break;
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<2; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &A[i][j]);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(A[0][i] == A[1][j]){
				result = max(result, trash(i, j));
				break;
			}
		}
	}
	printf("%d\n", result);
}