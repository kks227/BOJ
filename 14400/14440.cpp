#include <cstdio>
using namespace std;

struct M2{
	int a, b, c, d;
	M2(): M2(1, 0, 0, 1){}
	M2(int a1, int b1, int c1, int d1): a(a1), b(b1), c(c1), d(d1){}
};

M2 operator *(const M2 &A, const M2 &B){
	return M2(
		(A.a*B.a + A.b*B.c) % 100, (A.a*B.b + A.b*B.d) % 100,
		(A.c*B.a + A.d*B.c) % 100, (A.c*B.b + A.d*B.d) % 100
		);
}

M2 power(const M2 &A, int n){
	if(n == 1) return A;
	M2 T = power(A, n/2);
	T = T * T;
	if(n%2) T = T * A;
	return T;
}

int main(){
	int x, y, a0, a1, n;
	scanf("%d %d %d %d %d", &x, &y, &a0, &a1, &n);
	if(n == 0) printf("%02d\n", a0);
	else if(n == 1) printf("%02d\n", a1);
	else{
		M2 M = power(M2(x, y, 1, 0), n-1);
		printf("%02d\n", (M.a*a1 + M.b*a0) % 100);
	}
}