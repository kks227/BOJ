#include <cstdio>
#include <cmath>
using namespace std;

inline double cross(double x1, double y1, double x2, double y2){
	return abs(x1*y2 - x2*y1);
}

int main(){
	while(1){
		double x[6], y[6];
		bool all0 = true;
		for(int i=0; i<6; i++){
			scanf("%lf %lf", x+i, y+i);
			if(x[i] || y[i]) all0 = false;
		}
		if(all0) break;

		double k = cross(x[4]-x[3], y[4]-y[3], x[5]-x[3], y[5]-y[3])/2/cross(x[1]-x[0], y[1]-y[0], x[2]-x[0], y[2]-y[0]);
		double hx = x[0]+k*(x[2]-x[0]), hy = y[0]+k*(y[2]-y[0]);
		printf("%.3lf %.3lf %.3lf %.3lf\n", hx+x[1]-x[0], hy+y[1]-y[0], hx, hy);
	}
}