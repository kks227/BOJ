#include <cstdio>
using namespace std;

int dp[9][9];

int C(int n, int r){
	int &ret = dp[n][r];
	if(ret > 0) return ret;
	if(r == 0 || r == n) return ret = 1;
	return ret = C(n-1, r-1) + C(n-1, r);
}

int main(){
	int N, M, K, result = 0;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=K; i<=M; i++)
		if(i <= M && M-i <= N-M) result += C(M, i)*C(N-M, M-i);
	printf("%.10lf\n", 1.0*result/C(N, M));
}