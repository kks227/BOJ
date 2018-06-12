#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf("%lld\n", max((long long)(1.0*A/B*C), 1LL*A*B/C));
}