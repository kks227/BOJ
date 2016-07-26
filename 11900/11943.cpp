#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("%d\n", min(B+C, A+D));
}