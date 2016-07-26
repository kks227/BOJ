#include <cstdio>
using namespace std;

int main(){

	long long A, B;
	scanf("%lld %lld", &A, &B);
	if(A > B){
		A += B;
		B = A - B;
		A = A - B;
	}
	printf("%d\n", A==B?0:B-A-1);
	for(long long i=A+1; i<B; i++)
		printf("%lld ", i);

	return 0;
}