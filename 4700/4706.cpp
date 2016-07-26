#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	while(1){
		double a, b;
		scanf("%lf %lf", &a, &b);
		if(a == 0) break;
		printf("%.3lf\n", sqrt(1-pow(b/a, 2.0)));
	}
}