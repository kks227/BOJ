#include <cstdio>
#include <cstring>
using namespace std;

long long dp[90][2];

long long pinary(int digits, bool cur){
	long long &ret = dp[digits][cur];
	if(ret != -1) return ret;
	if(digits <= 1) return ret = digits;
	
	ret = pinary(digits-1, false);
	if(!cur) ret += pinary(digits-1, true);
	return ret;
}

void skip(int digits, bool cur, long long k){
	printf("%d", cur);
	if(digits == 1) return;

	long long pivot = pinary(digits-1, false);
	if(k < pivot) skip(digits-1, false, k);
	else skip(digits-1, true, k-pivot);
}

int main(){
	long long K, sum = 0;
	scanf("%lld", &K);
	memset(dp, -1, sizeof(dp));
	for(int i=1; ; i++){
		if(pinary(i, true)+sum >= K){
			skip(i, 1, K-sum-1);
			break;
		}
		sum += pinary(i, true);
	}
}