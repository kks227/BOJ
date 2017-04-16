#include <cstdio>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", A+B<C*2 ? A+B : A+B-C*2);
}