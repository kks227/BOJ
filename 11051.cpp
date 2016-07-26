#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 10007;
unsigned int C[1001][1001];

unsigned int Comb(int n, int k){
	unsigned int& ret = C[n][k];
	if(ret) return ret;
	if(k==0 || k==n) return ret = 1;
	return ret = (Comb(n-1, k-1) + Comb(n-1, k)) % MOD;
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d\n", Comb(N, K));
}