#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		long long X;
		scanf("%lld", &X);
		long long lo = 0, hi = 1e9;
		while(lo+1 < hi){
			long long mid = (lo+hi)/2;
			(mid*mid < X ? lo : hi) = mid;
		}
		printf("%d ", hi*hi == X);
	}
}