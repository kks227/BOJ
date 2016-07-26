#include <cstdio>
#include <cstring>
using namespace std;

int N, arr[100];
long long dp[99][21];

long long equations(int pos, int val){
	if(pos == N-1) return val==arr[pos];
	long long &ret = dp[pos][val];
	if(ret != -1) return ret;

	ret = 0;
	if(val+arr[pos] <= 20) ret += equations(pos+1, val+arr[pos]);
	if(pos>0 && val-arr[pos] >= 0) ret += equations(pos+1, val-arr[pos]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", equations(0, 0));
}