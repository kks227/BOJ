#include <cstdio>
using namespace std;

int N, C, D, M;
double dp[6][21], c[21][21];

double comb(int n, int r){
	double &ret = c[n][r];
	if(ret > 0) return ret;
	if(r == 0 || r == n) return ret = 1;
	return ret = comb(n-1, r-1) + comb(n-1, r);
}

// a: attached
double ecology(int d, int a){
	double ret = dp[d][a];
	if(ret >= 0) return ret;
	if(d == D) return ret = (a == M);

	ret = 0;
	for(int i=0; i<=C; i++)
		if(i <= a && C-i <= N-a)
			ret += comb(a, i)*comb(N-a, C-i)/comb(N, C) * ecology(d+1, a+C-i);
	return ret;
}

int main(){
	scanf("%d %d %d %d", &N, &C, &D, &M);
	for(int i=0; i<=5; i++)
		for(int j=0; j<=20; j++)
			dp[i][j] = -1;
	printf("%.10lf\n", ecology(0, 0));
}