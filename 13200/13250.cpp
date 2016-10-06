#include <cstdio>
#include <algorithm>
using namespace std;

double dp[1000001];

double dice(int n){
	double &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;

	ret = 0;
	for(int i=1; i<=6; i++)
		ret += dice(max(n-i, 0)) + 1;
	return ret /= 6;
}

int main(){
	int N;
	scanf("%d", &N);
	fill(dp, dp+1000001, -1);
	printf("%.10lf\n", dice(N));
}