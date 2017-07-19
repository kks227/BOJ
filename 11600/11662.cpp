#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long a, b, c;

double f(double t){ return a*t*t + b*t + c; }

int main(){
	int x[4], y[4];
	for(int i=0; i<4; i++)
		scanf("%d %d", x+i, y+i);
	long long p = x[1]-x[3]-x[0]+x[2], q = x[0]-x[2];
	long long r = y[1]-y[3]-y[0]+y[2], s = y[0]-y[2];
	a = p*p+r*r; b = 2*(p*q+r*s); c = q*q+s*s;
	double result = sqrt(min(f(0), f(1)));
	if(a > 0){
		double t = -b/2.0/a;
		if(0 <= t && t <= 1) result = min(sqrt(f(t)), result);
	}
	printf("%.6lf\n", result);
}