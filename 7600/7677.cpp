#include <cstdio>
using namespace std;
const int MOD = 10000;

struct Matrix{
	int e[2][2];
	Matrix(): Matrix(1, 0, 0, 1){}
	Matrix(int a, int b, int c, int d){
		e[0][0] = a;
		e[0][1] = b;
		e[1][0] = c;
		e[1][1] = d;
	}
	Matrix operator *(Matrix &O){
		Matrix result = Matrix(0, 0, 0, 0);
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<2; k++)
					result.e[i][j] = (result.e[i][j] + 1LL*e[i][k]*O.e[k][j]%MOD) % MOD;
		return result;
	}
};

Matrix power(Matrix A, long long n){
	if(n == 0) return Matrix();
	Matrix result = power(A, n/2);
	result = result * result;
	if(n%2) result = result * A;
	return result;
}

int fibo(int n){
	if(n == 0) return 0;
	return power(Matrix(1, 1, 1, 0), n-1).e[0][0];
}

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N < 0) break;
		printf("%d\n", fibo(N));
	}
}