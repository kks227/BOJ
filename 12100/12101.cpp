#include <cstdio>
#include <algorithm>
using namespace std;

int dp[11];

int add(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 1;

	ret = 0;
	for(int i=1; i<=min(n, 3); i++)
		ret += add(n-i);
	return ret;
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	fill(dp, dp+11, -1);
	if(add(N) < K){
		puts("-1");
		return 0;
	}

	bool init = true;
	while(N > 0){
		for(int i=1; i<=min(N, 3); i++){
			if(add(N-i) >= K){
				if(init) init = false;
				else putchar('+');
				printf("%d", i);
				N -= i;
				break;
			}
			K -= add(N-i);
		}
	}
}