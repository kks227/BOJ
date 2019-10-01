#include <cstdio>
using namespace std;
const int MAX = 15;

inline long long gcd(long long p, long long q){
	while(q > 0){
		long long r = p%q; p = q; q = r;
	}
	return p;
}

int main(){
	int N, a[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", a+i);
	long long p = a[N-1], q = 1;
	for(int i = N-2; i >= 0; --i){
		long long p1 = a[i], q1 = 1, p2 = q, q2 = p;
		p = p1*q2 + p2*q1;
		q = q1*q2;
		long long r = gcd(p, q);
		p /= r; q /= r;
	}
	printf("%lld %lld\n", p-q, p);
}