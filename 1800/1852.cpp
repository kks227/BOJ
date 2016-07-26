#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, val[100000][3];
long long dp1[100000][7], dp2[100000][7];

long long maxDiffSum(int n, int used){
	if(n == N) return 0;
	long long &ret = dp1[n][used];
	if(ret != -1) return ret;

	ret = 0;
	switch(used){
	case 0:
		ret = maxDiffSum(n+2, 0) + abs(val[n][0]-val[n+1][0]) + abs(val[n][1]-val[n+1][1]) + abs(val[n][2]-val[n+1][2]);
		ret = max(ret, maxDiffSum(n, 6) + abs(val[n][1]-val[n][2]));
		ret = max(ret, maxDiffSum(n, 3) + abs(val[n][0]-val[n][1]));
		break;
	case 1:
		ret = maxDiffSum(n+1, 0) + abs(val[n][1]-val[n][2]);
		if(n+1 < N) ret = max(ret, maxDiffSum(n+1, 6) + abs(val[n][1]-val[n+1][1]) + abs(val[n][2]-val[n+1][2]));
		break;
	case 3:
		ret = maxDiffSum(n+1, 4) + abs(val[n][2]-val[n+1][2]);
		break;
	case 4:
		ret = maxDiffSum(n+1, 0) + abs(val[n][0]-val[n][1]);
		if(n+1 < N) ret = max(ret, maxDiffSum(n+1, 3) + abs(val[n][0]-val[n+1][0]) + abs(val[n][1]-val[n+1][1]));
		break;
	case 6:
		ret = maxDiffSum(n+1, 1) + abs(val[n][0]-val[n+1][0]);
	}
	return ret;
}

long long minDiffSum(int n, int used){
	if(n == N) return 0;
	long long &ret = dp2[n][used];
	if(ret != -1) return ret;

	ret = 0x7fffffffffffffff;
	switch(used){
	case 0:
		ret = minDiffSum(n+2, 0) + abs(val[n][0]-val[n+1][0]) + abs(val[n][1]-val[n+1][1]) + abs(val[n][2]-val[n+1][2]);
		ret = min(ret, minDiffSum(n, 6) + abs(val[n][1]-val[n][2]));
		ret = min(ret, minDiffSum(n, 3) + abs(val[n][0]-val[n][1]));
		break;
	case 1:
		ret = minDiffSum(n+1, 0) + abs(val[n][1]-val[n][2]);
		if(n+1 < N) ret = min(ret, minDiffSum(n+1, 6) + abs(val[n][1]-val[n+1][1]) + abs(val[n][2]-val[n+1][2]));
		break;
	case 3:
		ret = minDiffSum(n+1, 4) + abs(val[n][2]-val[n+1][2]);
		break;
	case 4:
		ret = minDiffSum(n+1, 0) + abs(val[n][0]-val[n][1]);
		if(n+1 < N) ret = min(ret, minDiffSum(n+1, 3) + abs(val[n][0]-val[n+1][0]) + abs(val[n][1]-val[n+1][1]));
		break;
	case 6:
		ret = minDiffSum(n+1, 1) + abs(val[n][0]-val[n+1][0]);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &val[i][j]);
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	printf("%lld\n%lld\n", maxDiffSum(0, 0), minDiffSum(0, 0));
}