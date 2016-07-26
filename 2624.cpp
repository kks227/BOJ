#include <cstdio>
#include <cstring>
using namespace std;

int k, p[100], n[100];
long long dp[100][10001];

long long cntExchange(int pos, int cost){
	if(cost == 0) return 1;
	if(pos == k) return 0;
	long long &ret = dp[pos][cost];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=0; i<=n[pos]; i++){
		if(cost < i*p[pos]) break;
		ret += cntExchange(pos+1, cost-i*p[pos]);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d %d", &T, &k);
	for(int i=0; i<k; i++)
		scanf("%d %d", p+i, n+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cntExchange(0, T));
}