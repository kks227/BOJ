#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50000;

int dp[MAX+1];

int square(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n <= 1) return ret = n;
	ret = n;
	for(int i = 0; i*i <= n; ++i)
		ret = min(square(n - i*i), ret);
	return ++ret;
}

int main(){
	int N;
	scanf("%d", &N);
	fill(dp, dp+MAX+1, -1);
	printf("%d\n", square(N));
}