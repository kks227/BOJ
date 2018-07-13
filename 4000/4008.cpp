#include <cstdio>
#include <algorithm>
using namespace std;

struct Rational{
	long long p, q; // p/q
	Rational(): Rational(0, 1){}
	Rational(long long p1, long long q1): p(p1), q(q1){}
	bool operator <(const Rational &O)const{ return p*O.q < O.p*q; }
};

struct LinearFunc{ // f(x) = ax + b, x >= s
	long long a, b;
	Rational s;
	LinearFunc(): LinearFunc(1, 0){}
	LinearFunc(long long a1, long long b1): a(a1), b(b1), s(){}
};

inline Rational cross(LinearFunc &f, LinearFunc &g){
	return Rational(g.b-f.b, f.a-g.a);
}



int main(){
	int N, a, b, c, val[1000000], S[1000001] = {0};
	scanf("%d %d %d %d", &N, &a, &b, &c);
	for(int i=0; i<N; i++){
		scanf("%d", val+i);
		S[i+1] = S[i] + val[i];
	}

	long long dp[1000001] = {0};
	LinearFunc f[1000000];
	int top = 0;
	for(int i=1; i<=N; i++){
		LinearFunc g(-2*a*S[i-1], 1LL*a*S[i-1]*S[i-1] - 1LL*b*S[i-1] + dp[i-1]);
		while(top > 0){
			g.s = cross(g, f[top-1]);
			if(f[top-1].s < g.s) break;
			top--;
		}
		f[top++] = g;

		long long x = S[i];
		int fpos = top-1;
		if(Rational(x, 1) < f[top-1].s){
			int lo = 0, hi = top-1;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				(Rational(x, 1) < f[mid].s ? hi : lo) = mid;
			}
			fpos = lo;
		}
		dp[i] = f[fpos].a * x + f[fpos].b + 1LL*a*S[i]*S[i] + 1LL*b*S[i] + c;
	}
	printf("%lld\n", dp[N]);
}