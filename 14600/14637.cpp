#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
	int N, T, d[MAX], s[MAX];
	double lo = -1000000001, hi = 1000000001;
	scanf("%d %d", &N, &T);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", d+i, s+i);
		lo = max(-1.0*s[i], lo);
	}
	for(int k = 0; k < 100; ++k){
		double mid = (lo+hi)/2;
		if(mid == 0) break;
		double temp = 0;
		for(int i = 0; i < N; ++i)
			temp += d[i]/(s[i]+mid);
		if(temp == T) break;
		(temp < T ? hi : lo) = mid;
	}
	printf("%.10lf\n", (lo+hi)/2);
}