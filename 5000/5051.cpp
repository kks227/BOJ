#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const int MAX = 500000;
const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &f, bool inv = false){
	int n = f.size();
	for(int i = 1, j = 0; i < n; ++i){
		int b = n/2;
		while(!((j ^= b) & b)) b /= 2;
		if(i < j) swap(f[i], f[j]);
	}
	for(int k = 1; k < n; k *= 2){
		double a = (inv ? PI/k : -PI/k);
		cpx w(cos(a), sin(a));
		for(int i = 0; i < n; i += k*2){
			cpx wp(1, 0);
			for(int j = 0; j < k; ++j){
				cpx x = f[i+j], y = f[i+j+k] * wp;
				f[i+j] = x + y;
				f[i+j+k] = x - y;
				wp *= w;
			}
		}
	}
	if(inv){
		for(int i = 0; i < n; ++i)
			f[i] /= n;
	}
}

void multiply(vector<cpx> a, vector<cpx> b, vector<cpx> &c){
	int n = 1;
	while(n < a.size()+1 || n < b.size()+1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	c.resize(n);

	FFT(a);
	FFT(b);
	for(int i = 0; i < n; ++i)
		c[i] = a[i]*b[i];
	FFT(c, true);
}



int main(){
	int N, cnt1[MAX] = {0,}, cnt2[MAX] = {0,};
	scanf("%d", &N);
	for(int i = 1; i < N; ++i){
		++cnt1[1LL*i*i % N];
		++cnt2[2LL*i*i % N];
	}
	vector<cpx> A(N), B;
	for(int i = 0; i < N; ++i)
		A[i] = cpx(cnt1[i], 0);
	multiply(A, A, B);

	long long r1 = 0, r2 = 0;
	for(int i = 0; i < B.size(); ++i)
		r1 += cnt1[i%N] * (long long)round(B[i].real());
	for(int i = 0; i < N; ++i)
		r2 += 1LL*cnt1[i] * cnt2[i];
	printf("%lld\n", (r1-r2)/2+r2);
}