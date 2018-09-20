#include <cstdio>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	if(A == B) puts("==");
	else if(A > B) puts(">");
	else puts("<");
}