#include <cstdio>
using namespace std;

int main(){

	long long M, N;
	scanf("%lld %lld", &M, &N);
	if(M >= N){
		if(N == 1) printf("0\n%lld 1\n", M);
		else printf("%lld\n%lld %lld\n", (N-1)*2+(M!=N), N%2?M-N/2:N/2+1, (N+1)/2);
	}
	else{
		if(M == 1) printf("0\n1 %lld\n", N);
		else{
			printf("%lld\n", (M-1)*2);
			if(M % 2) printf("%lld %lld\n", (M+1)/2, N-M/2);
			else printf("%lld %lld\n", M/2+1, (M+1)/2);
		}
	}

	return 0;
}