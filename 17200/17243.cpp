#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500;

int N, K, A[MAX], dp[MAX+1][MAX+1];

int AKIS(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = 1;
	for(int i = pos+1; i < N; ++i){
		if(A[pos] <= A[i]) ret = max(AKIS(i, k)+1, ret);
		else if(k > 0) ret = max(AKIS(i, k-1)+1, ret);
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	int result = 1;
	for(int i = 0; i < N; ++i)
		result = max(AKIS(i, K), result);
	printf("%d\n", result);
}