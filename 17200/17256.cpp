#include <cstdio>
using namespace std;

int main(){
	int x[2], y[2], z[2];
	scanf("%d %d %d %d %d %d", x, y, z, x+1, y+1, z+1);
	printf("%d %d %d\n", x[1]-z[0], y[1]/y[0], z[1]-x[0]);
}