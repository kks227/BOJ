#include <cstdio>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n%d\n%d\n%d\n", (A+B)%C, (A%C+B%C)%C, A*B%C, (A%C*(B%C))%C);
}