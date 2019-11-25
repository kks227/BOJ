#include <cstdio>
using namespace std;

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%lld\n", 1LL*(a-2)*b*(b+1)/2+b+1);
}