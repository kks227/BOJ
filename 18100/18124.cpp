#include <cstdio>
using namespace std;

int main(){
	long long N, K = 1;
	scanf("%lld", &N);
	while(K < N) K *= 2;
	printf("%lld\n", K - 1 - (K-N)/2);
}