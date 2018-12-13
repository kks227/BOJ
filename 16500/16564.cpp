#include <cstdio>
using namespace std;

int main(){
	int N, K, X[1000000];
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", X+i);
	unsigned int lo = 0, hi = 2*(1e9)+1;
	while(lo+1 < hi){
		unsigned int mid = (lo+hi)/2;
		long long k = K;
		for(int i = 0; i < N; ++i)
			if(mid > X[i]) k -= mid-X[i];
		(k >= 0 ? lo : hi) = mid;
	}
	printf("%u\n", lo);
}