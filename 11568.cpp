#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, card[1000], dp[1000];

int LIS(int pos){
	if(pos == N) return 0;
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=pos+1; i<N; i++)
		if(card[pos] < card[i]) ret = max(ret, LIS(i));
	return ++ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", card+i);
	memset(dp, -1, sizeof(dp));
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, LIS(i));
	printf("%d\n", result);
}