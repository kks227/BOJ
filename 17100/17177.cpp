#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	double a1 = 2*asin(1.0*y/x), a2 = 2*asin(1.0*z/x), a3 = acos(-1)-a1-a2;
	if(a3 < 0) puts("-1");
	else printf("%.0lf\n", round(x*sin(a3/2)));
}