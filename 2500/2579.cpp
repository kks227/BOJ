#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, cost[300], cache[300][2];

int maxCost(int pos, bool consec){
	if(pos == N) return 0;
	int &ret = cache[pos][consec];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = cost[pos];
	if(pos == N-2) return ret = consec ? 0 : cost[pos]+cost[pos+1];
	ret = maxCost(pos+2, false);
	if(!consec) ret = max(ret, maxCost(pos+1, true));
	return ret += cost[pos];
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", cost+i);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", max(maxCost(0, false), maxCost(1, false)));
}