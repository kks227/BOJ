#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	long long N;
	scanf("%lld", &N);
	N /= 2;
	int result = N*2-1;
	for(long long i = 1; 2*i*i < N*N; ++i){
		long long j = round(sqrt(N*N - i*i));
		if(N*N == i*i + j*j) result -= 2;
	}
	printf("%d\n", result*4);
}