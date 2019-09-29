#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int X, Y, W, S;
	scanf("%d %d %d %d", &X, &Y, &W, &S);
	int p = min(X, Y), s = max(X, Y) - p, q = s/2*2, r = s-q;
	printf("%lld\n", 1LL*p*min(S, W*2) + 1LL*q*min(S, W) + r*W);
}