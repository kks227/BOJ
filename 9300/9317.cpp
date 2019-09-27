#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	while(1){
		double D, x, y;
		scanf("%lf %lf %lf", &D, &x, &y);
		if(D == 0) break;
		double W = 16*D/sqrt(337), H = W*9/16;
		printf("Horizontal DPI: %.2lf\nVertical DPI: %.2lf\n", x/W, y/H);
	}
}