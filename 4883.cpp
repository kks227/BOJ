#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int N, minCost[3], cost[3];
	for(unsigned int t=1; ; ++t){
		scanf("%d", &N);
		if(N==0) break;
		
		scanf("%d %d %d", minCost, minCost+1, minCost+2);
		minCost[0] = 0x7FFFFFFF;
		minCost[2] += minCost[1];
		for(unsigned int r=1; r<N; ++r){
			scanf("%d %d %d", cost, cost+1, cost+2);
			cost[0] += min(minCost[0], minCost[1]);
			cost[1] += min(min(cost[0], minCost[0]), min(minCost[1], minCost[2]));
			cost[2] += min(minCost[1], min(cost[1], minCost[2]));
			minCost[0] = cost[0];
			minCost[1] = cost[1];
			minCost[2] = cost[2];
		}
		printf("%u. %d\n", t, minCost[1]);
	}
	return 0;
}