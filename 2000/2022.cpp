#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	double x, y, c;
	while(scanf("%lf %lf %lf", &x, &y, &c) > 0){
		double lo = 0, hi = min(x, y);
		while(hi-lo > 1e-6){
			double mid = (lo+hi)/2;
			double a = sqrt(x*x-mid*mid), b = sqrt(y*y-mid*mid);
			(a*b/(a+b) < c ? hi : lo) = mid;
		}
		printf("%.3lf\n", lo);
	}
}