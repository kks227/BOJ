#include <cstdio>
using namespace std;
const int MOD = 1000000007;

int main(){
	int N;
	scanf("%d", &N);
	if(N < 2) printf("%d\n", N);
	else{
		int f[3] = {0, 1,};
		for(int i=2; i<=N; i++){
			f[2] = (f[0] + f[1]) % MOD;
			f[0] = f[1];
			f[1] = f[2];
		}
		printf("%d\n", f[1]);
	}
}