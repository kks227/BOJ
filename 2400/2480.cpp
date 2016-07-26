#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if(A==B && A==C) printf("%d\n", 10000+A*1000);
	else if(A==B || A==C) printf("%d\n", 1000+A*100);
	else if(B==C) printf("%d\n", 1000+B*100);
	else printf("%d\n", max(A, max(B, C))*100);
}