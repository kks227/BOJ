#include <cstdio>
using namespace std;
const int MOD = 1000000007;

struct Matrix2by2{
	int e[2][2];
	Matrix2by2(): Matrix2by2(1, 0, 0, 1){}
	Matrix2by2(int a, int b, int c, int d){
		e[0][0] = a;
		e[0][1] = b;
		e[1][0] = c;
		e[1][1] = d;
	}
	Matrix2by2 operator *(Matrix2by2 &O){
		Matrix2by2 result = Matrix2by2(0, 0, 0, 0);
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<2; k++)
					result.e[i][j] = (result.e[i][j] + 1LL*e[i][k]*O.e[k][j]%MOD) % MOD;
		return result;
	}
	Matrix2by2 power(long long n){
		if(n == 0) return Matrix2by2();
		Matrix2by2 S = this->power(n/2);
		if(n%2) return (*this)*S*S;
		return S*S;
	}
};

int fibo(long long n){
	if(n == 0) return 0;
	return Matrix2by2(1, 1, 1, 0).power(n-1).e[0][0];
}

int main(){
	long long N;
	scanf("%lld", &N);
	printf("%d\n", fibo((N+1)/2*2));
}