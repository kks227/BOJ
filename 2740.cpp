#include <cstdio>
using namespace std;

int main(){

	int A[100][100], B[100][100], C[100][100]={0};
	int N, M, K;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &A[i][j]);
	scanf("%d %d", &M, &K);
	for(int i=0; i<M; i++){
		for(int j=0; j<K; j++){
			scanf("%d", &B[i][j]);
			for(int k=0; k<N; k++)
				C[k][j] += A[k][i]*B[i][j];
		}
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<K; j++)
			printf("%d%c", C[i][j], (j==K-1)?'\n':' ');

	return 0;
}