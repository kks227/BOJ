#include <cstdio>
using namespace std;

inline int gcd(int p, int q){
	while(q){
		int r = p%q;
		p = q;
		q = r;
	}
	return p;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int p, q, r = 1, g;
		scanf("%d %d", &p, &q);
		while(p > 1){
			int lo = r, hi = q/p+1;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(p*mid>q ? hi : lo) = mid;
			}
			r = hi;
			g = gcd(p*r-q, q*r);
			p = (p*r-q)/g;
			q = (q*r)/g;
		}
		printf("%d\n", q);
	}
}