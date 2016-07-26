#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 3.1415916;

inline double deg2rad(double deg){
	return deg*PI/180;
}

int main(){
	double r, h, d1, A1, d2, A2;
	while(scanf("%lf %lf %lf %lf %lf %lf", &r, &h, &d1, &A1, &d2, &A2) > 0){
		double R = sqrt(h*h + r*r);
		double T = 2*PI*r/R;
		if(A1 > A2) swap(A1, A2);
		A2 -= A1;
		if(A2 > 180) A2 = 360 - A2;
		printf("%.2lf\n", sqrt(d1*d1+d2*d2 - 2*d1*d2*cos(deg2rad(A2) * T/2/PI)));
	}
}