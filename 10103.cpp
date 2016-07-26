#include <cstdio>
using namespace std;

int main(){

	int N, a, b, A, B;
	A = B = 100;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &a, &b);
		if(a > b) B -= a;
		else if(a < b) A -= b;
	}
	printf("%d\n%d\n", A, B);

	return 0;
}