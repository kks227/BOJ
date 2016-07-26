#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int X, Y, D, T;
	while(scanf("%d %d %d %d", &X, &Y, &D, &T) > 0){
		double dist = sqrt(X*X + Y*Y);
		int jump = dist/D;
		double spare = dist - jump*D;
		double result = dist;
		result = min(result, spare + jump*T);
		if(jump > 0) result = min(result, (jump+1)*T*1.0);
		else{
			result = min(result, D-spare + T);
			if(dist < D) result = min(result, T*2.0);
		}
		printf("%.10lf\n", result);
	}
}