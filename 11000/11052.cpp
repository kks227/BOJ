#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P[1000], dp[1000];

int sell(int remain){
	if(remain == 0) return 0;
	int &ret = dp[remain];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=0; i<remain; i++)
		ret = max(ret, P[i] + sell(remain-i-1));
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", P+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", sell(N));
}