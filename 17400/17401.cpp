#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100;
const int MAX_N = 20;
const int MOD = 1000000007;

struct Matrix{
	int N, e[MAX_N][MAX_N];
	Matrix(): Matrix(1){}
	Matrix(int N1): N(N1){ memset(e, 0, sizeof(e)); }
	Matrix operator *(const Matrix &O){
		Matrix R(N);
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				for(int k = 0; k < N; ++k)
					R.e[i][j] = (R.e[i][j] + 1LL*e[i][k]*O.e[k][j]) % MOD;
		return R;
	}
};

Matrix I(int N){
	Matrix R(N);
	for(int i = 0; i < N; ++i)
		R.e[i][i] = 1;
	return R;
}

Matrix power(Matrix M, int k){
	if(k == 0) return I(M.N);
	if(k == 1) return M;
	Matrix R = power(M, k/2);
	R = R * R;
	if(k%2) R = R * M;
	return R;
}



int main(){
	int T, N, D;
	Matrix M[MAX];
	scanf("%d %d %d", &T, &N, &D);
	for(int i = 0; i < T; ++i){
		int K;
		scanf("%d", &K);
		M[i].N = N;
		for(int j = 0; j < K; ++j){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			M[i].e[a-1][b-1] = c;
		}
	}

	Matrix S = I(N);
	for(int i = 0; i < T; ++i)
		S = S * M[i];
	Matrix R = power(S, D/T);
	for(int i = 0; i < D%T; ++i)
		R = R * M[i];
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			printf("%d ", R.e[i][j]);
		puts("");
	}
}