#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, k[2000001] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		k[val]++;
	}
	long long result = 0;
	for(int i=1; i<=2000000; i++){
		int cnt = 0;
		for(int j=i; j<=2000000; j+=i)
			cnt += k[j];
		if(cnt >= 2) result = max(1LL*cnt*i, result);
	}
	printf("%lld\n", result);
}