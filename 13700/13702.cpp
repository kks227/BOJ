#include <cstdio>
using namespace std;

int main(){
	int N, K, A[10000];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	long long lo = 0, hi = 1LL<<32;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		int cnt = 0;
		for(int i=0; i<N; i++)
			cnt += A[i] / mid;
		(cnt >= K ? lo : hi) = mid;
	}
	printf("%lld\n", lo);
}