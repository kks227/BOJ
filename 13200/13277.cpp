#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const int MAX = 1<<19;
const double PI = 3.14159265358979323846264;
typedef complex<double> cpx;

cpx b[MAX];

void FFT(cpx *a, int n, bool dft=false){
	if(n == 1) return;

	memcpy(b, a, sizeof(cpx)*n);
	for(int i=0; i<n; i++)
		a[i/2 + (i%2?n/2:0)] = b[i];
	cpx w(cos(2*PI/n), sin(2*PI/n));
	if(dft) w = cpx(1, 0)/w;
	FFT(a, n/2, dft);
	FFT(a+n/2, n/2, dft);

	cpx wp(1, 0);
	memcpy(b, a, sizeof(cpx)*n);
	for(int i=0; i<n/2; i++){
		a[i] = b[i] + wp*b[i+n/2];
		a[i+n/2] = b[i] - wp*b[i+n/2];
		wp *= w;
	}
}

int multiply(cpx *p, cpx *q, int pl, int ql, cpx *r){
	int n = 1;
	while(n < pl+1 || n < ql+1) n *= 2;
	n *= 2;
	FFT(p, n);
	FFT(q, n);

	for(int i=0; i<n; i++)
		r[i] = p[i]*q[i];
	FFT(r, n, true);
	for(int i=0; i<n; i++){
		r[i] /= cpx(n, 0);
		r[i] = cpx(round(r[i].real()), round(r[i].imag()));
	}
	return n;
}

int main(){
	char Ain[MAX]={0}, Bin[MAX]={0};
	cpx A[MAX], B[MAX], C[MAX];
	int Acnt=0, Bcnt=0, Alen=0, Blen=0, Clen;
	while(1){
		char c = getchar();
		if(c == ' ') break;
		Ain[Acnt++] = c-'0';
	}
	if(Acnt%2){
		for(int i=(Acnt-1)/2, j=0; i>0; i--)
			A[Alen++] = Ain[i*2-1]*10 + Ain[i*2];
		A[Alen++] = Ain[0];
	}
	else{
		for(int i=(Acnt-1)/2; i>=0; i--)
			A[Alen++] = Ain[i*2]*10 + Ain[i*2+1];
	}
	while(1){
		char c = getchar();
		if(c == '\n') break;
		Bin[Bcnt++] = c-'0';
	}
	if(Bcnt%2){
		for(int i=(Bcnt-1)/2, j=0; i>0; i--)
			B[Blen++] = Bin[i*2-1]*10 + Bin[i*2];
		B[Blen++] = Bin[0];
	}
	else{
		for(int i=(Bcnt-1)/2; i>=0; i--)
			B[Blen++] = Bin[i*2]*10 + Bin[i*2+1];
	}
	Clen = multiply(A, B, Alen, Blen, C);

	int carry = 0, i, R[MAX], Rlen = 0;
	for(i=0; i<Clen; i++){
		int temp = (int)C[i].real() + carry;
		R[Rlen++] = temp%10;
		temp /= 10;
		R[Rlen++] = temp%10;
		carry = temp/10;
	}
	while(carry > 0){
		R[Rlen++] = carry%10;
		carry /= 10;
	}
	for(i=Rlen-1; i>=0 && R[i]==0; i--);
	if(i < 0) puts("0");
	else{
		for(; i>=0; i--)
			putchar(R[i]+'0');
	}
}