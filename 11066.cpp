#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, page[500];
long long rs[501], dp[500][500];

long long minMerge(int s, int e){
	long long &ret = dp[s][e];
	if(ret != -1) return ret;
	if(s == e) return ret = 0;
	if(s+1 == e) return ret = page[s] + page[e];

	ret = 1000000000000000000;
	for(int i=s; i<e; i++)
		ret = min(ret, minMerge(s, i) + minMerge(i+1, e) + rs[e+1]-rs[s]);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		rs[0] = 0;
		for(int i=0; i<N; i++){
			scanf("%d", page+i);
			rs[i+1] = rs[i] + page[i];
		}
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", minMerge(0, N-1));
	}
}