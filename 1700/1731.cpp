#include <cstdio>
using namespace std;

int main(){
	int N, A[50];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	if(A[1]-A[0] == A[2]-A[1])
		printf("%d\n", A[N-1]+A[1]-A[0]);
	else
		printf("%d\n", A[N-1]*(A[1]/A[0]));
}