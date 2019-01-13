#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int INF = 1e9;

int N, A[MAX], dp[MAX+1][MAX+1][MAX+1];

int breakout(int pos, int k, int b){
	int &ret = dp[pos][k][b];
	if(ret != -1) return ret;
	if(pos == N) return ret = (b > 0 ? INF : 0);

	ret = breakout(pos+1, k+1, b) + (k != A[pos]);
	if(b > 0 && pos > 0) ret = min(breakout(pos+1, 1, b-1) + (A[pos] > 0), ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < N; ++i)
		printf("%d\n", breakout(0, 0, i));
}