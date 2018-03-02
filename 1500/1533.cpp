#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000003;

struct Matrix{
	int size;
	vector<vector<int>> A;
	Matrix(): size(0){}
	Matrix(int size1): size(size1){ A = vector<vector<int>>(size, vector<int>(size)); }
	Matrix operator *(const Matrix &O){
		Matrix result(size);
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
				for(int k=0; k<size; k++)
					result.A[i][j] = (result.A[i][j] + 1LL*A[i][k]*O.A[k][j]) % MOD;
		return result;
	}
};

Matrix power(Matrix M, int n){
	if(n == 1) return M;
	Matrix result = power(M, n/2);
	result = result * result;
	if(n%2) result = result * M;
	return result;
}

int main(){
	int N, S, E, T;
	scanf("%d %d %d %d", &N, &S, &E, &T);
	S--; E--;
	Matrix M(N*5);
	for(int i=0; i<N; i++)
		for(int j=1; j<5; j++)
			M.A[i*5+j][i*5+j-1] = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int d;
			scanf("%1d", &d);
			if(d == 1) M.A[i*5][j*5] = 1;
			else if(d > 1) M.A[i*5][j*5+d-1] = 1;
		}
	}
	M = power(M, T);
	printf("%d\n", M.A[S*5][E*5]);
}