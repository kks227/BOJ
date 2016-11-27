#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
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

void multiply(vector<cpx> &p, vector<cpx> &q, vector<cpx> &r){
	int n = 1;
	while(n < p.size()+1 || n < q.size()+1) n *= 2;
	n *= 2;
	p.resize(n);
	q.resize(n);
	r.resize(n);
	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(p, w);
	FFT(q, w);

	for(int i=0; i<n; i++)
		r[i] = p[i]*q[i];
	FFT(r, cpx(1, 0)/w);
	for(int i=0; i<n; i++){
		r[i] /= cpx(n, 0);
		r[i] = cpx(round(r[i].real()), round(r[i].imag()));
	}
}

int main(){
	int N;
	scanf("%d", &N);
	vector<cpx> X(N*2), Y(N), Z;
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		X[i] = X[i+N] = cpx(val, 0);
	}
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		Y[N-i-1] = cpx(val, 0);
	}

	int result = 0;
	multiply(X, Y, Z);
	for(int i=N-1; i<2*N-1; i++)
		result = max(result, (int)Z[i].real());
	printf("%d\n", result);
}