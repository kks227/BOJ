#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	long long a, b, c, d, s, t;
	scanf("%lld %lld %lld", &a, &b, &c);
	if(!a || !b){
		if(!a && !b) puts(c ? "NO" : "YES");
		else if(!a) puts(c%b ? "NO" : "YES");
		else puts(c%a ? "NO" : "YES");
		return 0;
	}
	if(a == c || b == c){
		puts("YES");
		return 0;
	}

	long long p = a, q = b;
	while(q){
		long long r = p % q;
		p = q;
		q = r;
	}
	d = p;

	if(c%d) puts("NO");
	else{
		long long x = 1;
		for(; (c-a*x)%b; x++);
		long long y = (c-a*x)/b;
		while(y > 0){
			long long p = x, q = y;
			while(q){
				long long r = p % q;
				p = q;
				q = r;
			}
			if(p == 1){
				puts("YES");
				return 0;
			}
			x += b/d;
			y -= a/d;
		}
		puts("NO");
	}
}