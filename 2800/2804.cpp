#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char A[31], B[31];
	int N, M;
	scanf("%s %s", A, B);
	N = strlen(A);
	M = strlen(B);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(A[i]==B[j]){
				char map[30][30] = {0};
				for(int k=0; k<N; k++)
					map[j][k] = A[k];
				for(int k=0; k<M; k++)
					map[k][i] = B[k];
				for(int k=0; k<M; k++){
					for(int l=0; l<N; l++)
						putchar(map[k][l]?map[k][l]:'.');
					puts("");
				}
				return 0;
			}
}