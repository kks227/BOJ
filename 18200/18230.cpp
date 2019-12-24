#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2000;

int main(){
	int N, A, B, a[MAX], b[MAX*2], result = 0;
	scanf("%d %d %d", &N, &A, &B);
	for(int i = 0; i < A; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < B; ++i)
		scanf("%d", b+i);
	sort(a, a+A);
	if(N%2) result += a[--A];
	N /= 2;
	for(int i = 0; i < A/2; ++i)
		b[B++] = a[A-i*2-1] + a[A-i*2-2];
	sort(b, b+B);
	for(int i = 0; i < N; ++i)
		result += b[B-i-1];
	printf("%d\n", result);
}