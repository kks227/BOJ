#include <cstdio>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", A ^ (C%2 ? B : 0));
}