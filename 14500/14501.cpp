#include <cstdio>
#include <algorithm>
using namespace std;

int N, T[15], P[15], dp[16];

int retire(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = retire(pos+1);
	if(pos+T[pos] <= N) ret = max(retire(pos+T[pos])+P[pos], ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", T+i, P+i);
	fill(dp, dp+16, -1);
	printf("%d\n", retire(0));
}