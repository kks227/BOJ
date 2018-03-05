#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline double d2(double x1, double y1, double x2, double y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

inline void normalize(double &x, double &y){
	double d = sqrt(x*x + y*y);
	x /= d; y /= d;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		double D;
		scanf("%d %lf", &N, &D);
		double x[32], y[32];
		for(int i=0; i<N; i++)
			scanf("%lf %lf", x+i, y+i);

		int result = 1;
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				double d = d2(x[i], y[i], x[j], y[j]);
				if(d > D*D) continue;
				if(d == 0){
					int cnt = 2;
					for(int k=0; k<N; k++){
						if(k == i || k == j) continue;
						if(d2(x[i], y[i], x[k], y[k]) <= D*D/4) cnt++;
					}
					result = max(result, cnt);
					continue;
				}

				double xM = (x[i]+x[j])/2, yM = (y[i]+y[j])/2, xD, yD;
				if(x[i] == x[j]){ xD = 1; yD = 0; }
				else if(y[i] == y[j]){ xD = 0; yD = 1; }
				else{
					xD = 1/(x[i]-x[j]);
					yD = 1/(y[j]-y[i]);
					normalize(xD, yD);
				}
				d = sqrt(D*D/4 - d/4);
				for(int sign=-1; sign<=1; sign+=2){
					int cnt = 2;
					double xO = xM + sign*xD*d, yO = yM + sign*yD*d;
					for(int k=0; k<N; k++){
						if(k == i || k == j) continue;
						if(d2(xO, yO, x[k], y[k]) <= D*D/4) cnt++;
					}
					result = max(result, cnt);
				}
			}
		}
		printf("%d\n", result);
	}
}