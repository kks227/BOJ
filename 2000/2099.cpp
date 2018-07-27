#include <cstdio>
#include <vector>
using namespace std;

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
					if(A[i][k] && O.A[k][j]) R.A[i][j] = 1;
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
	int N, K, Q;
	scanf("%d %d %d", &N, &K, &Q);
	Matrix::N = N;
	Matrix M;
	for(int i=0; i<N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		M.A[i][u-1] = M.A[i][v-1] = 1;
	}
	M = power(M, K);
	for(int i=0; i<Q; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		puts(M.A[u-1][v-1] > 0 ? "death" : "life");
	}
}