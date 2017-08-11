#include <cstdio>
#include <cstring>
using namespace std;

int N, dp[10][3];

int walk(int n, int m){
	int &ret = dp[n][m];
	if(ret != -1) return ret;
	if(n == N) return ret = !m;

	ret = 0;
	for(int i=!n; i<3; i++)
		ret += walk(n+1, (m+i)%3);
	return ret;
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", walk(0, 0));
}