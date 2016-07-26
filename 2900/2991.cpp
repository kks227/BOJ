#include <cstdio>
using namespace std;

int main(){

	int A, B, C, D, N;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	for(int i=0; i<3; i++){
		scanf("%d", &N);
		printf("%d\n", (N%(A+B)<=A && N%(A+B)>0) + (N%(C+D)<=C && N%(C+D)>0));
	}

	return 0;
}