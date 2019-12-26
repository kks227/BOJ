#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MAX = 1000;
const int MOD = 998244353;

int M, cnt[MAX], dp[MAX+1][MAX+1];

int setting(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = 1;
	if(pos == M) return ret = 0;
	return ret = (setting(pos+1, k) + 1LL*setting(pos+1, k-1)*cnt[pos]) % MOD;
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	unordered_map<int, int> H;
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		if(H.find(val) == H.end()) H[val] = M++;
		++cnt[H[val]];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", setting(0, K));
}