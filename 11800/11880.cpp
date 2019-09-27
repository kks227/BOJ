#include <cstdio>
#include <algorithm>
using namespace std;

inline long long p2(long long a){ return a*a; }

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		long long d[3], result = 1e18;
		scanf("%lld %lld %lld", d, d+1, d+2);
		for(int i = 0; i < 3; ++i)
			result = min(p2(d[(i+1)%3] + d[(i+2)%3]) + p2(d[i]), result);
		printf("%lld\n", result);
	}
}