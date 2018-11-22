#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, M, A[20], dp[21][21];

int group(int pos, int m){
	int &ret = dp[pos][m];
	if(ret != -1) return ret;
	if(m == 0) return ret = 0;
	if(pos == N) return ret = -INF;

	ret = group(pos+1, m);
	int sum = 0;
	for(int i = pos; i < N; ++i){
		sum += A[i];
		ret = max(group(i+1, m-1) + sum, ret);
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", group(0, M));
}