#include <cstdio>
using namespace std;

int main(){
	int A, B, N;
	scanf("%d %d %d", &A, &B, &N);
	A %= B;
	for(int i=0; i<N-1; i++) A = A*10%B;
	printf("%d\n", A*10/B);
}