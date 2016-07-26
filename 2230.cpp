#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A[100000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);

	int lo = 0, hi = 0, result = 0x7fffffff, dif = 0;
	while(lo < N){
		if(dif<=M && hi<N) dif = A[hi++] - A[lo];
		else dif = A[hi] - A[lo++];
		if(dif >= M) result = min(result, dif);
	}
	printf("%d\n", result);
}