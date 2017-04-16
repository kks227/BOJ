#include <cstdio>
using namespace std;

int main(){
	int N, A[300][300], B[300][300], result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &A[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &B[i][j]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			bool temp = 0;
			for(int k=0; k<N; k++)
				temp += A[i][k]*B[k][j];
			result += temp;
		}
	}
	printf("%d\n", result);
}