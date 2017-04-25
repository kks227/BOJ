#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int n, k;
		scanf("%d %d", &n, &k);
		if(n == 0) break;

		k = min(k, n-k);
		unsigned long long c = 1;
		for(int i=1; i<=k; i++)
			c = c*(n-i+1)/i;
		printf("%llu\n", c);
	}
}