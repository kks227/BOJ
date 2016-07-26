#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, cost[2][100000], cache[100000][3];

int maxCost(int pos, int status){
	if(pos == N) return 0;
	int &ret = cache[pos][status];
	if(ret != -1) return ret;
	ret = maxCost(pos+1, 0);
	if(status != 1) ret = max(ret, maxCost(pos+1, 1) + cost[1][pos]);
	if(status != 2) ret = max(ret, maxCost(pos+1, 2) + cost[0][pos]);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int i=0; i<2; i++)
			for(int j=0; j<N; j++)
				scanf("%d", &cost[i][j]);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", maxCost(0, 0));
	}
}