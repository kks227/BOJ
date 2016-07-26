#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

inline double dot(double x1, double y1, double x2, double y2){
	return x1*x2 + y1*y2;
}

inline double cross(double x1, double y1, double x2, double y2){
	return x1*y2 - x2*y1;
}

inline double renew(double x1, double y1, double x2, double y2, double x3, double y3){
	double dot1 = dot(x2-x1, y2-y1, x3-x1, y3-y1);
	double dot2 = dot(x1-x2, y1-y2, x3-x2, y3-y2);
	if(dot1*dot2>=0)
		return abs(cross(x2-x1, y2-y1, x3-x1, y3-y1))/distance(x1, y1, x2, y2);
	return -1;
}

int main(){
	int N, M;
	double yx[4000], yy[4000], result = -1;
	scanf("%d %d", &N, &M);

	for(int i=0; i<N*2; i++)
		scanf("%lf %lf", yx+i, yy+i);
	for(int i=0; i<M; i++){
		double x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%lf %lf %lf %lf", &x3, &y3, &x4, &y4);
		for(int j=0; j<N; j++){
			x1 = yx[j*2];
			x2 = yx[j*2+1];
			y1 = yy[j*2];
			y2 = yy[j*2+1];

			double dist = distance(x1, y1, x3, y3), temp;
			dist = min(dist, distance(x1, y1, x4, y4));
			dist = min(dist, distance(x2, y2, x3, y3));
			dist = min(dist, distance(x2, y2, x4, y4));

			temp = renew(x1, y1, x2, y2, x3, y3);
			if(temp >= 0) dist = min(dist, temp);
			temp = renew(x1, y1, x2, y2, x4, y4);
			if(temp >= 0) dist = min(dist, temp);
			temp = renew(x3, y3, x4, y4, x1, y1);
			if(temp >= 0) dist = min(dist, temp);
			temp = renew(x3, y3, x4, y4, x2, y2);
			if(temp >= 0) dist = min(dist, temp);

			if(result < 0) result = dist;
			else result = min(result, dist);
		}
	}
	printf("%.10lf\n", result);
}