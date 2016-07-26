#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI 3.141592653589793

inline double circle(double r){
	return PI*r*r;
}

inline double lune(double r, double d){
	double h = sqrt(r*r - d*d);
	double x = acos(d/r);
	return (x*r*r - d*h);
}

int main(){
	double x1, x2, y1, y2, r1, r2;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
	double sqrd = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

	if((r1+r2)*(r1+r2) <= sqrd) puts("0.000");
	else if((r1-r2)*(r1-r2) >= sqrd) printf("%.3lf\n", min(circle(r1), circle(r2)));
	else{
		double d = sqrt(sqrd);
		double x = (r1*r1 - r2*r2 + sqrd)/(2*d);
		printf("%.3lf\n", (lune(r1, x) + lune(r2, d-x)));
	}
}