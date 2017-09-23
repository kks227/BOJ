#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[1000], dp[1001][3];

int milk(int pos, int type = 0){
	int &ret = dp[pos][type];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = milk(pos+1, type);
	if(val[pos] == type) ret = max(milk(pos+1, (type+1)%3)+1, ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", milk(0));
}