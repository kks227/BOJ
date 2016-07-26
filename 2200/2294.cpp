#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define IMPOSSIBLE 10001

int N, K, cost[100];
int cache[10001][100];

int minCnt(int spare, int limit){
	if(limit < 0 || limit >= N) return IMPOSSIBLE;

	int& ret = cache[spare][limit];
	if(ret != -1) return ret;
	if(limit == 0){
		if(spare%cost[0]) return ret = IMPOSSIBLE;
		else return ret = spare/cost[0];
	}

	ret = IMPOSSIBLE;
	for(int i=0; spare>=cost[limit]*i; i++){
		ret = min(ret, minCnt(spare-cost[limit]*i, limit-1)+i);
	}

	return ret;
}

int main(){

	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", cost+i);

	memset(cache, -1, 10001*100*sizeof(int));
	sort(cost, cost+N);

	int result = minCnt(K, N-1);
	if(result != IMPOSSIBLE) printf("%d\n", result);
	else printf("-1\n");

	return 0;
}