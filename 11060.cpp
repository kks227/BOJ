#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int N, A[1000], dp[1000];

int jump(int pos){
	if(pos >= N-1) return 0;
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = INF;
	for(int i=1; i<=A[pos]; i++)
		ret = min(ret, jump(pos+i)+1);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", jump(0)<INF ? jump(0) : -1);
}