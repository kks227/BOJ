#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001];

int partition(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n <= 1) return ret = 1;

	ret = (n%2 ? 0 : partition(n/2));
	for(int i=1; i<=n; i++)
		if(n%2 == i%2) ret += partition((n-i)/2);
	return ret;
}

int main(){
	fill(dp, dp+1001, -1);
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		printf("%d\n", partition(N));
	}
}