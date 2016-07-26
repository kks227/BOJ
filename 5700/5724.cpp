#include <cstdio>
using namespace std;

int main(){

	int N;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		printf("%d\n", N*(N+1)*(2*N+1)/6);
	}

	return 0;
}