#include <cstdio>
using namespace std;

int main(){
	int N, A[250][250], B[250][250] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &A[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<N; k++)
				B[i][j] += A[i][k] * A[k][j];
	long long result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(i!=j) result += B[i][j]*(B[i][j]-1);
	printf("%lld\n", result);
}