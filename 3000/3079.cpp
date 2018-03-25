#include <cstdio>
using namespace std;

int main(){
	int N, M, T[100000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", T+i);
	long long lo = 0, hi = 1e18;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		long long sum = 0;
		for(int i=0; i<N; i++)
			sum += mid/T[i];
		(sum >= M ? hi : lo) = mid;
	}
	printf("%lld\n", hi);
}