#include <cstdio>
#include <cmath>
using namespace std;

bool isParallel(int a1, int b1, int a2, int b2){
	return a1*b2 == b1*a2;
}

void getIntersection(int a1, int b1, int c1, int a2, int b2, int c2, double &resultX, double &resultY){
	resultY = 1.0*(a1*c2 - a2*c1)/(a2*b1 - a1*b2);
	if(a1==0) resultX = 1.0*(-c2 - b2*resultY)/a2;
	else resultX = 1.0*(-c1 - b1*resultY)/a1;
}

int main(){

	int T;
	int a[3], b[3], c[3];
	double x[3], y[3];
	scanf("%d", &T);
	bool flag;
	for(int i=0; i<T; i++){
		for(int j=0; j<3; j++)
			scanf("%d %d %d", a+j, b+j, c+j);
		flag = false;
		for(int j=0; j<3; j++){
			if(isParallel(a[j], b[j], a[(j+1)%3], b[(j+1)%3])){
				flag = true;
				break;
			}
		}
		if(flag){
			printf("0.0000\n");
			continue;
		}
		
		for(int j=0; j<3; j++)
			getIntersection(a[j], b[j], c[j], a[(j+1)%3], b[(j+1)%3], c[(j+1)%3], x[j], y[j]);
		flag = false;
		for(int j=0; j<3; j++){
			if(x[j]==x[(j+1)%3] && y[j]==y[(j+1)%3]){
				flag = true;
				break;
			}
		}
		if(flag){
			printf("0.0000\n");
			continue;
		}

		printf("%.4f\n",
			sqrt(pow(x[0]-x[2], 2.0) + pow(y[0]-y[2], 2.0)) *
			abs(a[0]*x[1] + b[0]*y[1] + c[0]) / sqrt(0.0 + a[0]*a[0] + b[0]*b[0]) / 2 );
	}

	return 0;
}