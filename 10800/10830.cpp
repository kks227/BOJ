#include <cstdio>
#include <vector>
using namespace std;

int N;

vector<int> matrixMultiply(vector<int> &A, vector<int> &B){
	vector<int> C(N*N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<N; k++)
				C[i*N+j] = (C[i*N+j] + A[i*N+k] * B[k*N+j]) % 1000;
	return C;
}

vector<int> matrixPower(vector<int> &A, long long p){
	if(p == 1) return A;
	vector<int> C = matrixPower(A, p/2);
	C = matrixMultiply(C, C);
	if(p%2 == 1) C = matrixMultiply(C, A);
	return C;
}

int main(){
	long long B;
	scanf("%d %lld", &N, &B);
	vector<int> A(N*N), R;
	for(int i=0; i<N*N; i++)
		scanf("%d", &A[i]);
	R = matrixPower(A, B);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%d ", R[i*N+j]);
		puts("");
	}
}