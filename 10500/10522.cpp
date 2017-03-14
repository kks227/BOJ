#include <cstdio>
#include <cmath>
#include <cfloat>
using namespace std;
const double ERR = 1e-12;

int n;
double p, s, v;

inline double f(double c){
	return s*(1+1/c)/v + n*pow(log2(n), c*sqrt(2))/p/1e9;
}

inline double df(double c){
	return -s/v/c/c + n/p/1e9*sqrt(2)*log(log2(n))*pow(log2(n), c*sqrt(2));
}

int main(){
	scanf("%d %lf %lf %lf", &n, &p, &s, &v);
	double lo = 1e-60, hi = 1e60;
	while(hi-lo >= ERR){
		double mid = (lo+hi)/2;
		(df(mid) >= 0 ? hi : lo) = mid;
	}
	printf("%.8lf %.8lf\n", f(lo), lo);
}