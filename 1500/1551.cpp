#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int N, K, A[20], B[20];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		getchar();
		scanf("%d", A+i);
	}
	for(int i=1; i<=K; i++){
		for(int j=0; j<N-i; j++)
			B[j] = A[j+1]-A[j];
		memcpy(A, B, sizeof(A));
	}
	for(int i=0; i<N-K; i++)
		printf("%d%c", A[i], i==N-K-1 ? '\n' : ',');
}