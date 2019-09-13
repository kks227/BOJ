#include <cstdio>
#include <cmath>
using namespace std;
const double PI = 3.141592;

int main(){
	int d1, d2;
	scanf("%d %d", &d1, &d2);
	printf("%.9lf\n", d1*2 + d2*2*PI);
}