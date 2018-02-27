#include <cstdio>
using namespace std;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int tt=0; tt<T; tt++){
		int a, b, c, d, s, t;
		scanf("%d %d %d", &a, &b, &c);
		int r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
		while(r2){
			int q = r1 / r2;
			if(r1 < 0 && r1%r2) q--;
			int r = r1 - q*r2; r1 = r2; r2 = r;
			int s = s1 - q*s2; s1 = s2; s2 = s;
			int t = t1 - q*t2; t1 = t2; t2 = t;
		}
		d = r1; s = s1; t = t1;

		long long x0 = 1LL*c/d*s, y0 = 1LL*c/d*t, lo, hi;
		if(d < 0) d *= -1;
		int sign = (d > 0 ? 1 : -1);
		if(x0 > 0 && y0 > 0){
			lo = 0, hi = INF;
			while(lo+1 < hi){
				long long mid = (lo+hi)/2;
				(x0 + b/d*mid > 0 && y0 - a/d*mid > 0 ? lo : hi) = mid;
			}
		}
		else{
			lo = -INF, hi = 0;
			while(lo+1 < hi){
				long long mid = (lo+hi)/2;
				(x0 + b/d*mid <= 0 || y0 - a/d*mid <= 0 ? hi : lo) = mid;
			}
		}
		printf("%lld %lld\n", x0 + b/d*lo, y0 - a/d*lo);
	}
}