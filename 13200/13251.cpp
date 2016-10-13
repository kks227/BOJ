#include <cstdio>
using namespace std;

double dp[2501][2501];

double C(int n, int r){
	double &ret = dp[n][r];
	if(ret > 0) return ret;
	if(r == 0 || r == n) return ret = 1;
	return ret = C(n-1, r-1) + C(n-1, r);
}

int main(){
	int M, N=0, A[50], K;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d", A+i);
		N += A[i];
	}
	scanf("%d", &K);
	double result = 0;
	for(int i=0; i<M; i++)
		if(K <= A[i]) result += C(A[i], K);
	result /= C(N, K);
	printf("%.10lf\n", result);
}