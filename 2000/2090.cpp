#include <cstdio>
using namespace std;
typedef unsigned long long ull;

ull gcd(ull p, ull q){
	ull r;
	while(q){
		r = p%q;
		p = q;
		q = r;
	}
	return p;
}

int main(){
	int N;
	scanf("%d", &N);
	ull a1 = 0, a2 = 1;
	for(int i=0; i<N; i++){
		ull b1 = 1, b2, c1, c2;
		scanf("%llu", &b2);
		c1 = a1*b2 + a2*b1;
		c2 = a2*b2;
		ull g = gcd(c1, c2);
		a1 = c1/g;
		a2 = c2/g;
	}
	printf("%llu/%llu\n", a2, a1);
}