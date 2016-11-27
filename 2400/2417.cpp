#include <cstdio>
#include <climits>
#include <cmath>
using namespace std;

int main(){
	unsigned long long n, lo = 0, hi = LLONG_MAX;
	scanf("%llu", &n);
	if(n == 0){
		puts("0");
		return 0;
	}
	while(lo+1 < hi){
		unsigned long long mid = (lo+hi)/2;
		(mid*mid >= n ? hi : lo) = mid;
	}
	printf("%llu\n", hi);
}