#include <cstdio>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	if(A%2!=B%2 || A<B) puts("-1");
	else printf("%d %d\n", (A+B)/2, (A-B)/2);
}