#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int A, B;
	char C[102];
	scanf("%d %d %s", &A, &B, C);
	printf("%d\n", (C[strlen(C)-1]-'0')%2 ? A^B : A);
}