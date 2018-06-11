#include <cstdio>
using namespace std;
const int g = 10;

int main(){
	int V, W, D;
	scanf("%d %d %d", &V, &W, &D);
	double v = V, s = 0, tc = 1;
	int result = 0;
	while(1){
		double t = W/v*tc;
		s += g*t*t/2;
		if(s >= D) break;
		tc *= 1.25;
		result++;
	}
	printf("%d\n", result);
}