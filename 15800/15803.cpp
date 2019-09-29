#include <cstdio>
using namespace std;

int main(){
	int x[3], y[3];
	for(int i = 0; i < 3; ++i)
		scanf("%d %d", x+i, y+i);
	puts((x[2]-x[1])*(y[1]-y[0]) == (x[1]-x[0])*(y[2]-y[1]) ? "WHERE IS MY CHICKEN?" : "WINNER WINNER CHICKEN DINNER!");
}