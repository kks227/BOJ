#include <cstdio>
#include <cstring>
using namespace std;

int N, M, cost[20], cache[10001][21];

int possible(int spare, int limit){
	int& ret = cache[spare][limit];
	if(ret != -1) return ret;
	if(spare == 0) return ret = 1;
	if(limit == 1) return ret = (spare % cost[0] == 0);
	ret = 0;
	for(; spare>=0; spare-=cost[limit-1]){
		ret += possible(spare, limit-1);
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int j=0; j<N; j++)
			scanf("%d", cost+j);
		scanf("%d", &M);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", possible(M, N));
	}
}