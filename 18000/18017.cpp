#include <cstdio>
using namespace std;
const double c = 299792458;

int main(){
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.10lf\n", (a+b)/(1+a*b/c/c));
}