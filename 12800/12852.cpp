#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001], trace[1000001];

int make1(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 1) return ret = 0;

	ret = make1(n-1) + 1;
	if(n%3 == 0 && ret > make1(n/3)+1){
		ret = make1(n/3) + 1;
		trace[n] = 1;
	}
	if(n%2 == 0 && ret > make1(n/2)+1){
		ret = make1(n/2) + 1;
		trace[n] = 2;
	}
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	fill(dp, dp+N+1, -1);
	printf("%d\n", make1(N));
	while(N > 1){
		printf("%d ", N);
		switch(trace[N]){
			case 0: N--; break;
			case 1: N /= 3; break;
			default: N /= 2;
		}
	}
	puts("1");
}