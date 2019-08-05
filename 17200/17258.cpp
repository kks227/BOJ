#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 300;

int N, M, K, T, A[MAX], dp[MAX+1][MAX+1][MAX+1];

int party(int pos, int k, int remain){
	int &ret = dp[pos][k][remain];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	int nk = (A[pos]+k > T ? max(T-A[pos], 0) : k), spare = max(T-A[pos]-nk, 0);
	ret = party(pos+1, nk, remain) + !spare;
	if(spare > 0 && spare <= remain)
		ret = max(party(pos+1, nk+spare, remain-spare) + 1, ret);
	return ret;
}

int main(){
	scanf("%d %d %d %d", &N, &M, &K, &T);
	for(int i = 0; i < M; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		for(int j = s-1; j < e-1; ++j) ++A[j];
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", party(0, 0, K));
}