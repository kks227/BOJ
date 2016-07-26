#include <cstdio>
using namespace std;
const int MOD = 1234567;

int main(){
	int N, result = 0, p = 1, cnt = 1;
	scanf("%d", &N);
	while(N >= p*10LL){
		result = (result + p%MOD*9*cnt) % MOD;
		cnt++;
		p *= 10;
	}
	result = (result + (N-p+1)%MOD*cnt) % MOD;
	printf("%d\n", result);
}