#include <cstdio>
using namespace std;
const long long MOD = 1e12;

int main(){
	int N;
	long long result = 1;
	scanf("%d", &N);
	for(int i=2; i<=N; i++){
		result *= i;
		while(result % 10 == 0) result /= 10;
		result %= MOD;
	}
	printf("%05lld\n", result % 100000);
}