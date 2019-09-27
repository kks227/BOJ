#include <cstdio>
#include <algorithm>
using namespace std;
const double MAX = 1000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N;
		scanf("%d", &N);
		double x1 = MAX, x2 = -MAX, y1 = MAX, y2 = -MAX;
		for(int i = 0; i < N; ++i){
			double x, y;
			scanf("%lf %lf", &x, &y);
			x1 = min(x, x1); x2 = max(x, x2);
			y1 = min(y, y1); y2 = max(y, y2);
		}
		double w = x2-x1, h = y2-y1;
		printf("Case %d: Area %.10lf, Perimeter %.10lf\n", t, w*h, (w+h)*2);
	}
}