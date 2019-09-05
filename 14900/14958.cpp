#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const int MAX = 100000;
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
			cnt[k][i] = (int)round(C[M-1+k].real());
	}

	int result = 0;
	for(int i = 0; i < N; ++i)
		result = max(cnt[i][0]+cnt[i][1]+cnt[i][2], result);
	printf("%d\n", result);
}