#include <cstdio>
using namespace std;

long long c[21][21];

long long C(int n, int r){
	long long &ret = c[n][r];
	if(ret) return ret;
	if(r == 0 || r == n) return ret = 1;
	return ret = C(n-1, r-1) + C(n-1, r);
}

int main(){
	long long fact[21] = {1, 1};
	for(int i=2; i<=20; i++)
		fact[i] = fact[i-1] * i;
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		long long result = 0;
		for(int i=0, j=1; i<=N; i++, j*=-1)
			result += fact[N-i] * C(N, i) * j;
		printf("%lld\n", result);
	}
}