#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

struct rational{
	long long p, q; // p/q
	rational(): rational(0, 1){}
	rational(long long p1): rational(p1, 1){}
	rational(long long p1, long long q1): p(p1), q(q1){
		while(q){
			long long r = p % q;
			p = q;
			q = r;
		}
		q = q1/p;
		p = p1/p;
	}
	rational operator *(long long k){ return rational(p*k, q); }
	rational operator /(long long k){ return rational(p, q*k); }
	rational operator +(const rational& O){ return rational(p*O.q+q*O.p, q*O.q); }
	rational operator -(const rational& O){ return rational(p*O.q-q*O.p, q*O.q); }
};

inline rational abs(const rational &R){ return rational(abs(R.p), abs(R.q)); }
inline rational getY(long long x1, rational y1, long long x2, rational y2, long long x){ return y1 + (y2-y1)*(x-x1)/(x2-x1); }



int main(){
	int N;
	long long X[51], Y[51], S, E;
	scanf("%d", &N);
	for(int i=0; i<=N; i++)
		scanf("%lld %lld", X+i, Y+i);
	scanf("%lld %lld", &S, &E);

	vector<pair<long long, rational>> pos;
	for(int i=0; i<=N; i++){
		if(i < N && X[i] < S && S < X[i+1]) pos.push_back({S, getY(X[i], Y[i], X[i+1], Y[i+1], S)});
		if(S <= X[i] && X[i] <= E) pos.push_back({X[i], Y[i]});
		if(i > 0 && X[i-1] < E && E < X[i]) pos.push_back({E, getY(X[i-1], Y[i-1], X[i], Y[i], E)});
	}

	rational result = abs(pos.back().second - pos[0].second)/(E-S);
	if(result.q == 1) printf("%lld\n", result.p);
	else printf("%lld/%lld\n", result.p, result.q);
}