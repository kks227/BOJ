#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	if(K == 1){
		puts("1");
		return 0;
	}

	long long lo = 0, hi = 1LL*N*N+1;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2, cnt = 0;
		for(int i=1; i<=N; i++)
			cnt += min(mid/i, (long long)N);
		(cnt < K ? lo : hi) = mid;
	}
	printf("%lld\n", hi);
}