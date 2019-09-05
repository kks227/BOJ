#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const double PI = 3.14159265358979323846264;
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
		result = max(result, (int)round(Z[i].real()));
	printf("%d\n", result);
}