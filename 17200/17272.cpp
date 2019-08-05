#include <cstdio>
#include <vector>
using namespace std;
const int MAX_K = 10000;
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
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				for(int k = 0; k < N; ++k)
					R.A[i][j] = (R.A[i][j] + 1LL*A[i][k]*O.A[k][j]) % MOD;
		return R;
	}
};

Matrix power(Matrix M, long long k){
	if(k == 1) return M;
	if(k == 2) return M*M;

	Matrix R = power(M, k/2);
	R = R*R;
	if(k%2) R = R*M;
	return R;
}

int Matrix::N = 0;



int main(){
	int n, dp[MAX_K+1] = {1, 1,};
	long long k;
	scanf("%lld %d", &k, &n);
	for(int i = 2; i <= MAX_K; ++i){
		dp[i] = dp[i-1];
		if(i >= n) dp[i] = (dp[i] + dp[i-n]) % MOD;
	}
	if(k <= MAX_K){
		printf("%d\n", dp[k]);
		return 0;
	}

	Matrix::N = n;
	Matrix M;
	for(int i = 1; i < n; ++i)
		M.A[i-1][i] = 1;
	++M.A[n-1][0];
	++M.A[n-1][n-1];
	M = power(M, k-n+1);
	int result = 0;
	for(int i = 0; i < n; ++i)
		result = (result + 1LL*dp[i]*M.A[n-1][i]) % MOD;
	printf("%d\n", result);
}