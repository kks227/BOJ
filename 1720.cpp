#include <cstdio>
#include <cstring>
using namespace std;

int N;
int dp[31];

int cnt(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n <= 1) return 1;
	return ret = cnt(n-1) + cnt(n-2) * 2;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	int result;
	if(N%2) result = (cnt(N) + cnt((N-1)/2))/2;
	else result = (cnt(N) + cnt(N/2) + 2*cnt((N-2)/2))/2;
	printf("%d\n", result);
}