#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K;
	unsigned int A[50000];
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%u", A+i);
	sort(A, A+N);

	int lo = -1, hi = A[N-1];
	while(lo+1 < hi){
		unsigned int mid = (lo+hi)/2, pos = 0;
		for(int i = 0; i < K && pos < N; ++i)
			pos = upper_bound(A, A+N, A[pos]+mid*2) - A;
		(pos == N ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}