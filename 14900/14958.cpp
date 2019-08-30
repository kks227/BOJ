#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const int MAX = 100000;
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

void multiply(vector<cpx> &a, vector<cpx> &b, vector<cpx> &c){
	int n = 1;
	while(n < a.size()+1 || n < b.size()+1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	c.resize(n);

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
}



int main(){
	int N, M, cnt[MAX][3] = {0,};
	char S[MAX+1], T[MAX+1], action[3] = {'R', 'P', 'S'};
	scanf("%d %d %s %s", &N, &M, S, T);
	for(int i = 0; i < 3; ++i){
		int j = (i+2)%3;
		vector<cpx> A(N), B(M), C;
		for(int k = 0; k < N; ++k)
			if(S[k] == action[j]) A[k] = cpx(1, 0);
		for(int k = 0; k < M; ++k)
			if(T[k] == action[i]) B[M-k-1] = cpx(1, 0);
		
		multiply(A, B, C);
		for(int k = 0; k < N; ++k)
			cnt[k][i] = C[M-1+k].real();
	}

	int result = 0;
	for(int i = 0; i < N; ++i)
		result = max(cnt[i][0]+cnt[i][1]+cnt[i][2], result);
	printf("%d\n", result);
}