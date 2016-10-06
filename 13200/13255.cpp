#include <cstdio>
#include <algorithm>
using namespace std;

int N, K, A[50];
double dp[1001][51], C[1001][1001];

double comb(int n, int r){
	double &ret = C[n][r];
	if(ret >= 0) return ret;
	if(r == 0 || r == n) return ret = 1;
	return ret = comb(n-1, r-1) + comb(n-1, r);
}

double coins(int h, int k){
	double &ret = dp[h][k];
	if(ret >= 0) return ret;
	if(k == K) return ret = h;

	ret = 0;
	for(int i=0; i<=A[k]; i++){
		if(N-h-(A[k]-i) < 0 || h-i < 0) continue;
		ret += comb(h, i)*comb(N-h, A[k]-i)/comb(N, A[k]) * coins(h+A[k]-2*i, k+1);
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<K; i++)
		scanf("%d", A+i);
	for(int i=0; i<=N; i++){
		fill(dp[i], dp[i]+K+1, -1);
		fill(C[i], C[i]+N+1, -1);
	}
	printf("%.10lf\n", coins(N, 0));
}