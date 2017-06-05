#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	A--; B--;
	printf("%d\n", (int)abs(A/4-B/4) + (int)abs(A%4-B%4));
}