#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, P[20][20], dp[20][1048576];

int maxSuc(int pos, int unused){
	if(pos == N) return 1;
	int &ret = dp[pos][unused];
	if(ret != -1) return ret;

	ret = 0;
	int status = unused;
	while(status){
		int use = log2(status & -status);
		long long temp = 1LL * maxSuc(pos+1, unused-(1<<use)) * P[pos][use];
		if(pos < N-4)
			temp = temp/100 + (temp%100 >= 50);
		ret = max(ret, (int)temp);
		status &= (status-1);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &P[i][j]);
	memset(dp, -1, sizeof(dp));
	long long result = maxSuc(0, (1<<N)-1) * 1000000LL;
	int loop = min(N-1, 3);
	for(int i=0; i<loop; i++) result /= 100;
	printf("%lld.%06lld\n", result/1000000, result%1000000);
}