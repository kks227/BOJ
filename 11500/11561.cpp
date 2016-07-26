#include <cstdio>
#include <cmath>
using namespace std;

long long N;

bool jump(long long least){
	return (least*(least+1)/2 <= N);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%lld", &N);
		long long lo = 1, hi = sqrt(N+1)*2;
		while(lo+1 < hi){
			long long mid = (lo+hi)/2;
			if(jump(mid)) lo = mid;
			else hi = mid;
		}
		printf("%lld\n", lo);
	}
}