#include <cstdio>
#include <cstring>
using namespace std;

int dp[1001][3];

int hobby(int n, int k){
	int &ret = dp[n][k];
	if(ret != -1) return ret;
	if(k == 2) return ret = (n > 0);

	ret = 0;
	for(int i = n-1; i > 0; --i)
		ret += hobby(i, k+1);
	return ret;
}

int main(){
	int N;
	scanf("%d", &N);
	N /= 3;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", hobby(N, 0));
}