#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 100000007;

struct Matrix{
	int size;
	vector<vector<int>> e;
	Matrix(): Matrix(1){}
	Matrix(int n): size(n){ e = vector<vector<int>>(n, vector<int>(n)); }
	Matrix operator *(const Matrix& O){
		Matrix result(size);
		for(int i = 0; i < size; ++i)
			for(int j = 0; j < size; ++j)
				for(int k = 0; k < size; ++k)
					result.e[i][j] = (result.e[i][j] + 1LL*e[i][k]*O.e[k][j]) % MOD;
		return result;
	}
	Matrix power(int k){
		if(k == 1) return *this;
		Matrix result = power(k/2);
		result = result * result;
		if(k%2) result = (*this) * result;
		return result;
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int K, N;
		scanf("%d %d", &K, &N);
		if(N <= K){
			printf("%d\n", 1);
			continue;
		}

		Matrix M(K+1);
		for(int i = 0; i <= K; ++i)
			M.e[i][(i+1)%(K+1)] = 1;
		++M.e[K][K];
		M = M.power(N-K);
		int result = 0;
		for(int i = 0; i <= K; ++i)
			result = (result + M.e[K][i]) % MOD;
		printf("%d\n", result);
	}
}