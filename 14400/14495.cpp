#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	if(N <= 3) puts("1");
	else{
		unsigned long long f0 = 1, f1 = 1, f2 = 1, f3;
		for(int i=4; i<=N; i++){
			f3 = f0 + f2;
			f0 = f1;
			f1 = f2;
			f2 = f3;
		}
		printf("%llu\n", f2);
	}
}