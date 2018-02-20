#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long LIMIT = (1e18) + 1;

int N;
long long K, dp[201][201];

long long paren(int remain, int opened){
	long long &ret = dp[remain][opened];
	if(ret != -1) return ret;
	if(remain == opened) return ret = 1;
	if(remain < opened) return ret = 0;
	if(remain == 0) return ret = 0;

	ret = paren(remain-1, opened+1);
	if(opened > 0) ret += paren(remain-1, opened-1);
	return ret = min(ret, LIMIT);
}

void trace(int remain, int opened, long long k){
	if(remain == 0){
		puts("");
		return;
	}

	long long pivot = paren(remain-1, opened+1);
	if(pivot <= k){
		putchar(')');
		trace(remain-1, opened-1, k-pivot);
	}
	else{
		putchar('(');
		trace(remain-1, opened+1, k);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=1; t<=T; t++){
		scanf("%d %lld", &N, &K);
		printf("Case #%d: ", t);
		if(paren(N*2, 0) < K) puts("Doesn't Exist!");
		else trace(N*2, 0, K-1);
	}
}