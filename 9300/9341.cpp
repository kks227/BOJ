#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 1000000009;

class Matrix{
public:
	static int N;
	vector<vector<int>> A;
	Matrix(){
		A = vector<vector<int>>(N, vector<int>(N, 0));
	}
	Matrix operator *(const Matrix& O)const{
		Matrix R;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int k=0; k<N; k++)
					R.A[i][j] = (R.A[i][j] + 1LL*A[i][k]*O.A[k][j]) % MOD;
		return R;
	}
};

Matrix power(Matrix& M, int k){
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
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int A, B, C, D, S[102];
		scanf("%d %d %d %d", &A, &B, &C, &D);

		Matrix::N = C+2;
		Matrix M;
		for(int i=0; i<Matrix::N; i++){
			M.A[i][0] = 1;
			if(i == 0){
				S[i] = B;
				M.A[i][1] = 1;
			}
			else{
				S[i] = A;
				for(int j=2; j<=i; j++)
					M.A[i][j] = 1;
			}
		}
		M = power(M, D-1);
		int result = 0;
		for(int i=0; i<Matrix::N; i++)
			result = (1LL*M.A[Matrix::N-1][i]*S[i] + result) % MOD;
		printf("%d\n", result);
	}
}