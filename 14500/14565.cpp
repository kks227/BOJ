#include <cstdio>
using namespace std;

inline long long mod(long long n, long long a){
	if(a >= 0) return a % n;
	return (a + (-a/n+1)*n) % n;
}

int main(){
	long long N, A;
	scanf("%lld %lld", &N, &A);
	printf("%lld ", N-A);
	long long r1 = N, r2 = A, t1 = 0, t2 = 1;
	while(r2 > 0){
		long long q = r1/r2, r = r1 - q*r2, t = t1 - q*t2;
		r1 = r2; r2 = r;
		t1 = t2; t2 = t;
	}
	printf("%lld\n", r1 == 1 ? mod(N, t1) : -1);
}