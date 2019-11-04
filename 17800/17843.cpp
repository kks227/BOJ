#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int h, m, s;
		scanf("%d %d %d", &h, &m, &s);
		double a[3] = {h/12.0 + m/60.0/12 + s/60.0/60/12, m/60.0 + s/60.0/60, s/60.0};
		double result = 1;
		for(int i = 0; i < 3; ++i)
			for(int j = i+1; j < 3; ++j)
				result = min(min(abs(a[i]-a[j]), 1-abs(a[i]-a[j])), result);
		printf("%.10lf\n", result*360);
	}
}