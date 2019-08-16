#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 100;

inline double distance(int x, int y){ return sqrt(x*x + y*y); }

int main(){
	int T;
	scanf("%d", &T);
	const double PI = acos(-1);
	for(int t = 0; t < T; ++t){
		int N;
		double result = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if(x1*y2 == x2*y1) continue;
			double a = (x1*x2 + y1*y2)/(distance(x1, y1)*distance(x2, y2));
			result += acos(a)/(2.0*PI);
		}
		printf("%.5lf\n", round(result*1e5)/1e5);
	}
}