#include <cstdio>
#include <vector>
using namespace std;

int MOD;

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
	while(1){
		int N, A, B, C, T, S[50];
		scanf("%d %d %d %d %d %d", &N, &MOD, &A, &B, &C, &T);
		if(N == 0) break;
		for(int i=0; i<N; i++)
			scanf("%d", S+i);

		Matrix::N = N;
		Matrix M;
		for(int i=0; i<N; i++){
			if(i-1 >= 0) M.A[i][i-1] = A;
			M.A[i][i] = B;
			if(i+1 < N) M.A[i][i+1] = C;
		}
		M = power(M, T);
		for(int i=0; i<N; i++){
			int result = 0;
			for(int j=0; j<N; j++)
				result = (result + M.A[i][j] * S[j]) % MOD;
			printf("%d ", result);
		}
		puts("");
	}
}