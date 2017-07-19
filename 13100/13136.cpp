#include <cstdio>
using namespace std;

int main(){
	int R, C, N;
	scanf("%d %d %d", &R, &C, &N);
	R--; C--;
	printf("%lld\n", 1LL*(R/N+1)*(C/N+1));
}