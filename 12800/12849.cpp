#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000007;

class Matrix{
public:
	static int N;
	vector<vector<int>> A;
	Matrix(){
		A = vector<vector<int>>(N, vector<int>(N, 0));
	}
	Matrix operator *(const Matrix O)const{
		Matrix R;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int k=0; k<N; k++)
					R.A[i][j] = (R.A[i][j] + 1LL*A[i][k]*O.A[k][j]) % MOD;
		return R;
	}
};

Matrix power(Matrix M, int k){
	if(k == 0){
		Matrix E;
		for(int i=0; i<Matrix::N; i++)
			E.A[i][i] = 1;
		return E;
	}
	if(k == 1) return M;

	Matrix R = power(M, k/2);
	R = R*R;
	if(k%2) R = R*M;
	return R;
}

int Matrix::N = 0;



int main(){
	int D;
	Matrix::N = 8;
	Matrix M;
	M.A[0][1] = M.A[1][0] = 1;
	M.A[0][2] = M.A[2][0] = 1;
	M.A[1][2] = M.A[2][1] = 1;
	M.A[1][3] = M.A[3][1] = 1;
	M.A[2][3] = M.A[3][2] = 1;
	M.A[2][4] = M.A[4][2] = 1;
	M.A[3][4] = M.A[4][3] = 1;
	M.A[3][5] = M.A[5][3] = 1;
	M.A[4][5] = M.A[5][4] = 1;
	M.A[4][6] = M.A[6][4] = 1;
	M.A[5][7] = M.A[7][5] = 1;
	M.A[6][7] = M.A[7][6] = 1;
	scanf("%d", &D);
	M = power(M, D);
	printf("%d\n", M.A[0][0]);
}