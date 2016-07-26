#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int N, uni[100000], sel[99999], dp[100000][2];

int choice(int cur, bool chosen){
	if(cur == N) return 1;
	int &ret = dp[cur][chosen];
	if(ret != -1) return ret;

	if(chosen){
		ret = choice(cur+1, false);
		if(cur+1 < N)
			ret = (ret + 1LL*sel[cur]*choice(cur+1, true) % MOD) % MOD;
	}
	else{
		ret = 1LL*uni[cur]*choice(cur+1, false) % MOD;
		if(cur+1 < N){
			ret = (ret + 1LL*sel[cur]*choice(cur+1, false) % MOD) % MOD;
			ret = (ret + 1LL*sel[cur]*uni[cur] % MOD * choice(cur+1, true) % MOD) % MOD;
			ret = (ret + 1LL*sel[cur]*(sel[cur]-1) % MOD * choice(cur+1, true) % MOD) % MOD;
		}
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", uni+i);
	for(int i=0; i<N-1; i++)
		scanf("%d", sel+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", choice(0, false));
}