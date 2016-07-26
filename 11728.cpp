#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A[1000000], B[1000000], result[2000000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	for(int i=0; i<M; i++)
		scanf("%d", B+i);
	merge(A, A+N, B, B+M, result);
	for(int i=0; i<N+M; i++)
		printf("%d ", result[i]);
}