#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, pos[10000];
long long A, B, dp[10001][41];

long long park(int i, int b){
	long long &ret = dp[i][b];
	if(ret != -1) return ret;
	long long bcost = 0;
	if(b > 0){
		bcost = B;
		for(int j = 0; j < b; ++j)
			bcost += A * abs(pos[i-j-1] - pos[i-b/2-1]);
	}
	if(i == N) return ret = bcost;

	ret = min(park(i+1, 0) + A*pos[i], park(i+1, 1)) + bcost;
	if(b < 40) ret = min(park(i+1, b+1), ret);
	return ret;
}

int main(){
	scanf("%d %lld %lld", &N, &A, &B);
	for(int i = 0; i < N; ++i)
		scanf("%d", pos+i);
	sort(pos, pos+N);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", park(0, 0));
}