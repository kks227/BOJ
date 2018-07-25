#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[61];

long long road(int h){
	long long &ret = dp[h];
	if(ret != -1) return ret;
	if(h <= 1) return ret = 1;

	ret = 1;
	for(int i=0; i<h-1; i++)
		ret += 2*road(i);
	return ret;
}

int main(){
	int H;
	scanf("%d", &H);
	fill(dp, dp+61, -1);
	printf("%lld\n", road(H));
}