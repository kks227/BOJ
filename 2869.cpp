#include <cstdio>
using namespace std;

int main(){
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	if(A >= V) puts("1");
	else printf("%d\n", (V-A)/(A-B)+((V-A)%(A-B)>0)+1);
}