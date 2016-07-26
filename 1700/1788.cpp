#include <cstdio>
using namespace std;
const int MOD = 1000000000;

int main(){
	int N, fibo[1000001] = {0, 1};
	for(int i=2; i<=1000000; i++)
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
	scanf("%d", &N);
	if(N == 0) printf("0\n0\n");
	else if(N > 0) printf("1\n%d\n", fibo[N]);
	else printf("%d\n%d\n", ((-N)%2 ? 1 : -1), fibo[-N]);
}