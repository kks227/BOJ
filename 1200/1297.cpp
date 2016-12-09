#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int d, p, q;
	scanf("%d %d %d", &d, &p, &q);
	double x = d/sqrt(p*p+q*q);
	printf("%d %d\n", (int)(p*x), (int)(q*x));
}