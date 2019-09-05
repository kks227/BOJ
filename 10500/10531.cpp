#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <complex>
using namespace std;
const int MAX = 200000;
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

void power(vector<cpx> &p){
	int n = 1;
	while(n < p.size()+1) n *= 2;
	n *= 2;
	p.resize(n);
	FFT(p);
	for(int i = 0; i < n; ++i)
		p[i] = p[i]*p[i];
	FFT(p, true);
}

int main(){
	int N, M;
	scanf("%d", &N);
	vector<cpx> p(MAX+1);
	set<int> result;
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		p[val] = cpx(1, 0);
		result.insert(val);
	}
	power(p);
	for(int i = 0; i < p.size(); ++i)
		if(round(p[i].real()) > 0) result.insert(i);

	int cnt = 0;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int val;
		scanf("%d", &val);
		if(result.find(val) != result.end()) cnt++;
	}
	printf("%d\n", cnt);
}