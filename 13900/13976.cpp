#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000007;

struct Matrix{
	int size;
	vector<vector<int>> A;
	Matrix(): size(0){}
	Matrix(int size1): size(size1){ A = vector<vector<int>>(size, vector<int>(size)); }
	Matrix operator *(const Matrix &O){
		Matrix result(size);
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
				for(int k = 0; k < size; ++k)
					result.A[i][j] = (result.A[i][j] + 1LL*A[i][k]*O.A[k][j]) % MOD;
		return result;
	}
};

Matrix power(Matrix M, long long n){
	if(n == 1) return M;
	Matrix result = power(M, n/2);
	result = result * result;
	if(n%2) result = result * M;
	return result;
}

int main(){
	long long N;
	scanf("%lld", &N);
	if(N%2){
		puts("0");
		return 0;
	}

	Matrix M(6);
	M.A[5][4] = 3;
	M.A[3][4] = 2;
	M.A[0][3] = M.A[1][4] = M.A[2][5] = M.A[3][0] = M.A[4][5] = M.A[5][0] = 1;
	M = power(M, N-1);
	int a[6] = {1, 0, 1, 0, 1, 0}, result = 0;
	for(int i = 0; i < 6; i += 2)
		result = (result + M.A[3][i]) % MOD;
	printf("%d\n", result);
}