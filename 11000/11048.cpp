#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, cache[1000][1000], candy[1000][1000];

int maxCandies(int r, int c){
	int &ret = cache[r][c];
	if(ret != -1) return ret;
	ret = 0;
	if(r < N-1) ret = max(ret, maxCandies(r+1, c));
	if(c < M-1) ret = max(ret, maxCandies(r, c+1));
	if(r < N-1 && c < M-1) ret = max(ret, maxCandies(r+1, c+1));
	return ret += candy[r][c];
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%d", &candy[i][j]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", maxCandies(0, 0));
}