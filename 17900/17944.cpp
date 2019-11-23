#include <cstdio>
using namespace std;

int main(){
	int N, T;
	scanf("%d %d", &N, &T);
	int p = N*2-1, q = --T/p;
	printf("%d\n", q%2 ? 2*N-T%p : T%p+1);
}