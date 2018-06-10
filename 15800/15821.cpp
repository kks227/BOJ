#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K;
	long long val[100000] = {0};
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int P;
		scanf("%d", &P);
		for(int j=0; j<P; j++){
			long long x, y;
			scanf("%lld %lld", &x, &y);
			val[i] = max(x*x+y*y, val[i]);
		}
	}
	sort(val, val+N);
	printf("%lld.00\n", val[K-1]);
}