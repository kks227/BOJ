#include <cstdio>
using namespace std;

inline long long gcd(long long p, long long q){
	while(q){
		long long r = p%q;
		p = q;
		q = r;
	}
	return p;
}

int main(){
	long long a, b, A, B, lo, hi;
	scanf("%lld %lld", &a, &b);
	lo = 0, hi = (1<<30)+1;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		(mid*mid <= a ? lo : hi) = mid;
	}
	A = lo;
	lo = 0, hi = (1<<30)+1;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		(mid*mid <= b ? lo : hi) = mid;
	}
	B = lo;
	long long p = B-A, q = b-a;
	if(p == 0) puts("0");
	else{
		long long r = gcd(p, q);
		printf("%lld/%lld\n", p/r, q/r);
	}
}