#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[2000], dp[2000][2000];

int longest(int pos, int prev){
	int &ret = dp[pos][prev];
	if(ret != -1) return ret;

	int *p = lower_bound(val+pos+1, val+N, val[pos]*2-val[prev]);
	int next = p - val;
	if(next < N && val[next] == val[pos]*2-val[prev]) return ret = longest(next, pos) + 1;
	return ret = 2;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	sort(val, val+N);
	memset(dp, -1, sizeof(dp));
	int result = 1;
	for(int i=1; i<N; i++)
		for(int j=0; j<i; j++)
			result = max(result, longest(i, j));
	printf("%d\n", result);
}