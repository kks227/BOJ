#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N, x1, y1, x2, y2, x0, y0;
	scanf("%d %d %d", &N, &x0, &y0);
	x1 = x0; y1 = y0;
	long long sum = 0;
	for(int i=1; i<N; i++){
		scanf("%d %d", &x2, &y2);
		sum += 1LL*(x1+x2)*(y1-y2);
		x1 = x2; y1 = y2;
	}
	sum += 1LL*(x1+x0)*(y1-y0);
	printf("%.1lf\n", abs(sum)/2.0);
}