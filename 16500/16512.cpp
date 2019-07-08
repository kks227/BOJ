#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5000;
const long long IMPOSSIBLE = -1e18;

int N, K, A[MAX];
bool visited[MAX+1][MAX+1][2];
long long dp[MAX+1][MAX+1][2];

long long kms(int pos, int k, bool expanding){
	long long &ret = dp[pos][k][expanding];
	if(visited[pos][k][expanding]) return ret;
	visited[pos][k][expanding] = true;
	if(pos == N) return ret = (k == K ? 0 : IMPOSSIBLE);

	ret = kms(pos+1, k, false);
	if(expanding) ret = max(kms(pos+1, k, true) + A[pos], ret);
	if(k < K) ret = max(kms(pos+1, k+1, true) + A[pos], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	printf("%lld\n", kms(0, 0, false));
}