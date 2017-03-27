#include <cstdio>
using namespace std;
const int MOD = 1000000007;

int main(){
	long long A[64] = {1}, X, result = 1;
	scanf("%lld %lld", &A[1], &X);
	A[1] %= MOD;
	for(int i=2; i<64; i++)
		A[i] = (1LL*A[i-1]*A[i-1]) % MOD;
	for(int i=0; i<63; i++)
		if(X & 1LL<<i) result = (1LL*result*A[i+1]) % MOD;
	printf("%lld\n", result);
}