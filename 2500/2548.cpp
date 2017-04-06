#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A[20000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);
	printf("%d\n", A[N/2 - !(N%2)]);
}