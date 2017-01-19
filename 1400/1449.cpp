#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, L, A[1000];
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);

	int result = 0, p = 0;
	do{
		result++;
		p = lower_bound(A+p, A+N, A[p]+L) - A;
	}while(p < N);
	printf("%d\n", result);
}