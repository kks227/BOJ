#include <cstdio>
using namespace std;
const int MOD = 1000000007;

int main(){
	long long A[64], X, result = 1;
	scanf("%lld %lld", &A[0], &X);
	A[1] %= MOD;
	for(int i=1; i<64; i++)
		A[i] = (1LL*A[i-1]*A[0]) % MOD;
	for(int i=0; i<63; i++)
		if(X & 1LL<<i) result = (1LL*result*A[i]) % MOD;
	printf("%lld\n", result);
}