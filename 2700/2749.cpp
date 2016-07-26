#include <cstdio>
using namespace std;
const int MOD = 1000000;
const int P = MOD/10 * 15;

int main(){
	int fibo[P] = {0, 1};
	for(int i=2; i<P; i++)
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
	long long N;
	scanf("%lld", &N);
	printf("%d\n", fibo[N%P]);
}