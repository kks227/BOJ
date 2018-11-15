#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int x[3], y[3];
	for(int i = 0; i < 3; ++i)
		scanf("%d %d", x+i, y+i);
	int val[2] = {max(abs(x[2]-x[0]), abs(y[2]-y[0])), abs(x[2]-x[1]) + abs(y[2]-y[1])};
	if(val[0] == val[1]) puts("tie");
	else if(val[0] < val[1]) puts("bessie");
	else puts("daisy");
}