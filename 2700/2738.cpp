#include <cstdio>
using namespace std;

int main(){

	int A[100][100], B[100][100];
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &A[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &B[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			printf("%d%c", A[i][j]+B[i][j], (j==M-1)?'\n':' ');

	return 0;
}