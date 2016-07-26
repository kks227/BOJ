#include <cstdio>
#include <cstring>
using namespace std;

long long dp[65][10];

long long cnt(int pos, int d){
	long long &ret = dp[pos][d];
	if(ret != -1) return ret;
	if(pos == 0) return ret = 1;

	ret = 0;
	for(int i=d; i>=0; i--)
		ret += cnt(pos-1, i);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%lld\n", cnt(N, 9));
	}
}