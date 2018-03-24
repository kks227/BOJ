#include <cstdio>
using namespace std;

int main(){
	int a, d, k;
	scanf("%d %d %d", &a, &d, &k);
	if((k-a)%d) puts("X");
	else printf("%d\n", (k-a)/d+1);
}