#include <cstdio>
#include <cstring>
using namespace std;

int dp[32][32];
char result[32];

int binary(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(m==0 || n==0) return ret = 1;
	
	ret = binary(n-1, m);
	if(m > 0) ret += binary(n-1, m-1);
	return ret;
}

void skip(int n, int m, int k, int p){
	if(n == 0) return;
	if(m == 0){
		for(int i=0; i<n; i++)
			result[p+i] = '0';
		return;
	}

	int pivot = binary(n-1, m);
	if(k < pivot){
		result[p] = '0';
		skip(n-1, m, k, p+1);
	}
	else{
		result[p] = '1';
		skip(n-1, m-1, k-pivot, p+1);
	}
}

int main(){
	int N, L;
	long long I;
	scanf("%d %d %lld", &N, &L, &I);
	memset(dp, -1, sizeof(dp));
	skip(N, L, I-1, 0);
	puts(result);
}