#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int K, N;
	long long len[10000], lo = 1, hi = -1;
	scanf("%d %d", &K, &N);
	for(int i=0; i<K; i++){
		scanf("%lld", len+i);
		hi = max(hi, len[i]+1);
	}
	while(lo+1 < hi){
		long long mid = (lo+hi)/2, cnt = 0;
		for(int i=0; i<K; i++)
			cnt += len[i]/mid;
		if(cnt >= N) lo = mid;
		else hi = mid;
	}
	printf("%lld\n", lo);
}