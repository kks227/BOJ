#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, cost[200][2], cache[200][3][200];
const int IMPOSSIBLE = -2;

int maxCost(int pos, int prevStatus, int spare){
	if(spare > N-pos) return IMPOSSIBLE;
	if(pos == N) return spare?IMPOSSIBLE:0;
	int& ret = cache[pos][prevStatus][spare];
	if(ret != -1) return ret;
	ret = maxCost(pos+1, 0, spare);
	if(ret != IMPOSSIBLE) ret += cost[pos][0] + cost[pos][1];
	if(spare){
		if(prevStatus!=1){
			int temp = maxCost(pos+1, 2, spare-1);
			if(temp != IMPOSSIBLE) ret = max(ret, temp + cost[pos][1]);
		}
		if(prevStatus!=2){
			int temp = maxCost(pos+1, 1, spare-1);
			if(temp != IMPOSSIBLE) ret = max(ret, temp + cost[pos][0]);
		}
	}
	return ret;
}

int main(){
	while(1){
		scanf("%d %d", &N, &K);
		if(N==0) break;
		for(int i=0; i<N; i++)
			scanf("%d %d", &cost[i][0], &cost[i][1]);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", maxCost(0, 0, K));
	}
}