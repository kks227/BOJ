#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	double result = sqrt(a) * sqrt(b);
	printf("%.3lf %.3lf\n", result, result);
}