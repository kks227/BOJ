#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int N, M, dp[105][51];
bool R[100];

int resort(int day, int coupon){
	int &ret = dp[day][coupon];
	if(ret != -1) return ret;
	if(day >= N) return ret = 0;

	ret = INF;
	if(R[day]) ret = resort(day+1, coupon);
	else if(coupon >= 3) ret = resort(day+1, coupon-3);
	else ret = resort(day+1, coupon) + 10;
	ret = min(ret, resort(day+3, coupon+1) + 25);
	ret = min(ret, resort(day+5, coupon+2) + 37);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int val;
		scanf("%d", &val);
		R[val-1] = true;
	}
	if(N == M){
		puts("0");
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	printf("%d000\n", resort(0, 0));
}