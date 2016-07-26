#include <cstdio>
using namespace std;

int main(){

	int K, N, M;
	scanf("%d %d %d", &K, &N, &M);
	printf("%d\n", K*N<=M?0:K*N-M);

	return 0;
}