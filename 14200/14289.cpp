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
	int V, E, D;
	scanf("%d %d", &V, &E);
	Matrix::N = V;
	Matrix M;
	for(int i=0; i<E; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		M.A[u][v] = M.A[v][u] = 1;
	}
	scanf("%d", &D);
	M = power(M, D);
	printf("%d\n", M.A[0][0]);
}