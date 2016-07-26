#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int A, B, C, D, P;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
	printf("%d\n", min(P*A, B+max(P-C, 0)*D));
}