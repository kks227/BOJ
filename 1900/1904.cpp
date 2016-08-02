#include <cstdio>
using namespace std;
const int MOD = 15746;

int main(){
	int N, f0=0, f1=1, f2;
	scanf("%d", &N);
	for(int i=2; i<=N+1; i++){
		f2 = (f0 + f1) % MOD;
		f0 = f1;
		f1 = f2;
	}
	printf("%d\n", f1);
}