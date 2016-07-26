#include <cstdio>
using namespace std;
const int MOD = 1000000000;

int main(){
	int N, f[1000001] = {0, 0, 1};
	scanf("%d", &N);
	for(int i=3; i<=N; i++)
		f[i] = 1LL*(i-1)*(f[i-1]+f[i-2]) % MOD;
	printf("%d\n", f[N]);
}