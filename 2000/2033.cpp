#include <cstdio>
using namespace std;

int main(){
	long long N, p10 = 10;
	scanf("%lld", &N);
	while(N > p10){
		if(N%p10 >= p10/2) N = N/p10*p10+p10;
		else N = N/p10*p10;
		p10 *= 10;
	}
	printf("%lld\n", N);
}