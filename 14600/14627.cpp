#include <cstdio>
using namespace std;

int main(){
	int S, C, L[1000000];
	scanf("%d %d", &S, &C);
	for(int i=0; i<S; i++)
		scanf("%d", L+i);

	int lo = 1, hi = 1000000001;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		long long cnt = 0;
		for(int i=0; i<S; i++)
			cnt += L[i] / mid;
		(cnt >= C ? lo : hi) = mid;
	}
	long long result = 0;
	for(int i=0; i<S; i++)
		result += L[i] % lo;
	printf("%lld\n", result);
}