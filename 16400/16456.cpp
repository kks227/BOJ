#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50000;
const int MOD = 1000000009;

int N, dp[MAX];

int tour(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos >= N-2) return ret = 1;
	if(pos == N-3) return ret = 2;
	ret = tour(pos+1);
	if(pos < N-3) ret = (tour(pos+3) + ret) % MOD;
	return ret;
}

int main(){
	scanf("%d", &N);
	fill(dp, dp+N, -1);
	printf("%d\n", tour(0));
}