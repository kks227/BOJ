#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <complex>
using namespace std;
const int MAX = 200000;
const double PI = 3.14159265358979323846264;
typedef complex<double> cpx;

void FFT(vector<cpx> &a, cpx w){
	int n = a.size();
	if(n == 1) return;

	vector<cpx> even(n/2), odd(n/2);
	for(int i=0; i<n; i++)
		(i%2 ? odd : even)[i/2] = a[i];
	FFT(even, w*w);
	FFT(odd, w*w);
	cpx wp(1, 0);
	for(int i=0; i<n/2; i++){
		a[i] = even[i] + wp*odd[i];
		a[i+n/2] = even[i] - wp*odd[i];
		wp *= w;
	}
}

void power(vector<cpx> &p){
	int n = 1;
	while(n < p.size()+1) n *= 2;
	n *= 2;
	p.resize(n);
	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(p, w);
	for(int i=0; i<n; i++)
		p[i] = p[i]*p[i];
	FFT(p, cpx(1, 0)/w);
	for(int i=0; i<n; i++)
		p[i] /= cpx(n, 0);
}

int main(){
	int N, M;
	scanf("%d", &N);
	vector<cpx> p(MAX+1);
	set<int> result;
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		p[val] = cpx(1, 0);
		result.insert(val);
	}
	power(p);
	for(int i=0; i<p.size(); i++)
		if(round(p[i].real()) > 0) result.insert(i);

	int cnt = 0;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int val;
		scanf("%d", &val);
		if(result.find(val) != result.end()) cnt++;
	}
	printf("%d\n", cnt);
}