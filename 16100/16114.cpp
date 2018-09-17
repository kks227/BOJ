#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int X, N;
	scanf("%d %d", &X, &N);
	if(N == 0) puts(X>0 ? "INFINITE" : "0");
	else if(N == 1) puts(X<0 ? "INFINITE" : "0");
	else if(N%2 == 1) puts("ERROR");
	else if(X < 0) puts("0");
	else printf("%d\n", max(X-1, 0)/(N/2));
}