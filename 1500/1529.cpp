#include <cstdio>
#include <set>
using namespace std;
const int MOD = 1234567891;

struct Matrix{
	int a[2][2];
	Matrix(){
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	}
	Matrix(int p, int q, int r, int s){
		a[0][0] = p % MOD; a[0][1] = q % MOD;
		a[1][0] = r % MOD; a[1][1] = s % MOD;
	}
	Matrix operator *(const Matrix &O){
		Matrix result;
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<2; k++)
					result.a[i][j] = (result.a[i][j] + 1LL*a[i][k]*O.a[k][j]) % MOD;
		return result;
	}
};

const Matrix I(1, 0, 0, 1);

Matrix power(Matrix M, int k){
	if(k == 0) return I;
	if(k == 1) return M;
	Matrix result = power(M, k/2);
	result = result * result;
	if(k%2) result = result * M;
	return result;
}

int main(){
	int N, L;
	scanf("%d %d", &N, &L);
	set<int> cnt[2][2];
	for(int i=0; i<N; i++){
		int val, f, l;
		bool invalid = false;
		scanf("%d", &val);
		int temp = val;
		l = temp % 10;
		while(temp){
			int d = temp % 10;
			if(d != 4 && d != 7){
				invalid = true;
				break;
			}
			f = d;
			temp /= 10;
		}
		if(!invalid) cnt[l==7][f==7].insert(val);
	}

	Matrix A;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			A.a[i][j] = cnt[i][j].size();
	int init[2] = {(A.a[0][0]+A.a[0][1]) % MOD, (A.a[1][0]+A.a[1][1]) % MOD};
	Matrix S = power(A, L-1);
	int result[2] = {0,};
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			result[i] = (result[i] + 1LL*S.a[i][j]*init[j]) % MOD;
	printf("%lld\n", (0LL+result[0]+result[1]) % MOD);
}