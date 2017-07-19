#include <cstdio>
using namespace std;

int main(){
	long long A, B;
	scanf("%lld %lld", &A, &B);
	long long p = A, q = B;
	while(q){
		long long r = p%q;
		p = q;
		q = r;
	}
	printf("%lld\n", A*B/p);
}