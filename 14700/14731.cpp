#include <cstdio>
using namespace std;
const int MOD = 1000000007;

long long power(int n, int k){
	if(k == 0) return 1;
	if(k == 1) return n;
	long long result = power(n, k/2);
	result = result * result % MOD;
	if(k%2) result = result * n % MOD;
	return result;
}

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		long long C, K;
		scanf("%lld %lld", &C, &K);
		if(K > 0) result = (result + C * K % MOD * power(2, K-1)) % MOD;
	}
	printf("%d\n", result);
}