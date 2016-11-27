#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int x[4], y[4], a, b, c, d, g;
		for(int i=0; i<4; i++)
			scanf("%d %d", x+i, y+i);
		a = x[1]-x[0]; b = y[1]-y[0];
		c = x[3]-x[2]; d = y[3]-y[2];
		if(a*d == b*c) puts(a*(y[2]-y[0]) == b*(x[2]-x[0]) ? "LINE" : "NONE");
		else{
			double u = 1.0*(d*(x[2]-x[0])-c*(y[2]-y[0])) / (a*d-b*c);
			printf("POINT %.2lf %.2lf\n", x[0]+u*a, y[0]+u*b);
		}
	}
}