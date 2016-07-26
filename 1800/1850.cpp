#include <cstdio>
using namespace std;

int main(){
	long long A, B, C;
	scanf("%lld %lld", &A, &B);
	while(B){
		C = A%B;
		A = B;
		B = C;
	}
	for(long long i=0; i<A; i++) putchar('1');
}