#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		long long x[4], y[4], d[6];
		for(int i = 0, k = 0; i < 4; ++i){
			scanf("%lld %lld", x+i, y+i);
			for(int j = 0; j < i; ++j, ++k)
				d[k] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
		}
		sort(d, d+6);
		puts(d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[3]*2==d[4] && d[4]==d[5] ? "1" : "0");
	}
}