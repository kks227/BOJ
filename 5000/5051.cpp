#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const int MAX = 500000;
const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
	int n = f.size();
	if(n == 1) return;

	vector<cpx> even(n/2), odd(n/2);
	for(int i = 0; i < n; ++i)
		(i%2 ? odd : even)[i/2] = f[i];

	FFT(even, w*w);
	FFT(odd, w*w);

	cpx wp(1, 0);
	for(int i = 0; i < n/2; ++i){
		f[i] = even[i] + wp*odd[i];
		f[i + n/2] = even[i] - wp*odd[i];
		wp *= w;
	}
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
	int n = 1;
	while(n < a.size()+1 || n < b.size()+1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	vector<cpx> c(n);

	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(a, w);
	FFT(b, w);

	for(int i = 0; i < n; ++i)
		c[i] = a[i]*b[i];

	FFT(c, cpx(1, 0)/w);
	for(int i = 0; i < n; ++i){
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}



int main(){
	int N, cnt1[MAX] = {0,}, cnt2[MAX] = {0,};
	scanf("%d", &N);
	for(int i = 1; i < N; ++i){
		++cnt1[1LL*i*i % N];
		++cnt2[2LL*i*i % N];
	}
	vector<cpx> A(N);
	for(int i = 0; i < N; ++i)
		A[i] = cpx(cnt1[i], 0);
	vector<cpx> B = multiply(A, A);

	long long r1 = 0, r2 = 0;
	for(int i = 0; i < B.size(); ++i)
		r1 += cnt1[i%N] * (long long)B[i].real();
	for(int i = 0; i < N; ++i)
		r2 += 1LL*cnt1[i] * cnt2[i];
	printf("%lld\n", (r1-r2)/2+r2);
}