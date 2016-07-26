#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Pole{
	int x, i;
	Pole(): Pole(0, 0){}
	Pole(int x1, int i1): x(x1), i(i1){}
	bool operator <(const Pole &O)const{
		return 1LL*x*O.i < 1LL*O.x*i;
	}
};

int main(){
	int N, x[100000];
	scanf("%d", &N);
	Pole pole[100000];
	for(int i=0; i<N; i++){
		scanf("%d", x+i);
		pole[i] = Pole(x[i], i);
	}
	sort(pole, pole+N);

	long long cnt = 1LL * N*(N-1)/2, pivot = cnt/2;
	int pos = 0;
	while(pivot >= pole[pos].i)
		pivot -= pole[pos++].i;
	int d = pole[pos].x / pole[pos].i;
	long long r1 = 0, r2 = 0;
	for(int i=1; i<N; i++){
		r1 += abs(x[i] - 1LL*d*i);
		r2 += abs(x[i] - 1LL*(d+1)*i);
	}
	printf("%lld\n", min(r1, r2));
}