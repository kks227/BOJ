#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, start, W[16][16], cache[16][65536];
const int IMPOSSIBLE = 1000000000;

int TSP(int current, int visited){
	if(visited == (1<<N)-1) return W[current][start]?W[current][start]:IMPOSSIBLE;
	int &ret = cache[current][visited];
	if(ret != -1) return ret;
	ret = IMPOSSIBLE;
	for(int i=0; i<N; i++){
		if(visited & (1<<i)) continue;
		if(W[current][i]==0) continue;
		ret = min(ret, TSP(i, visited | (1<<i)) + W[current][i]);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &W[i][j]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", TSP(0, 1));
}