#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100000;
const int MOD = 1000000007;

int N, dp[MAX+1][6];
char W[MAX][26], S[6] = "UNIST";

int unist(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(k == 5) return ret = 1;
	if(pos == N) return ret = 0;

	ret = unist(pos+1, k);
	for(int j = 0; W[pos][j] && W[pos][j] == S[k+j]; ++j)
		ret = (unist(pos+1, k+j+1) + ret) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%s", W[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", unist(0, 0));
}