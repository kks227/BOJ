#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int MAX_T = 2001;

int N, K, M, A[MAX], B[MAX], C[MAX], dp[MAX][MAX][2][MAX_T+1];

int pokemon(int s, int e, bool side, int t){
	int &ret = dp[s][e][side][t];
	if(ret != -1) return ret;
	if(t == MAX_T) return ret = 0;

	ret = 0;
	int pos = side ? e : s;
	if(s > 0) ret = max(pokemon(s-1, e, false, min(t+A[pos]-A[s-1], MAX_T)), ret);
	if(e < M-1) ret = max(pokemon(s, e+1, true, min(t+A[e+1]-A[pos], MAX_T)), ret);
	if(t < C[pos]) ret += B[pos];
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &K, &M);
	for(int i = 0; i < M; ++i)
		scanf("%d %d %d", A+i, B+i, C+i);
	memset(dp, -1, sizeof(dp));
	int s = lower_bound(A, A+M, K) - A, result = 0;
	if(s < M) result = pokemon(s, s, true, A[s]-K);
	if(s > 0 && A[s] != K) result = max(pokemon(s-1, s-1, false, K-A[s-1]), result);
	printf("%d\n", result);
}