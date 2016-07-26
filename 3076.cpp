#include <cstdio>
using namespace std;

int main(){

	int R, C, A, B;
	scanf("%d %d %d %d", &R, &C, &A, &B);
	for(int i=0; i<R*A; i++){
		for(int j=0; j<C*B; j++){
			if(i%(A*2) < A == j%(B*2) < B) putchar('X');
			else putchar('.');
		}
		putchar('\n');
	}

	return 0;
}