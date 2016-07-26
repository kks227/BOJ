#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int map[500][500];
int cache[500][500];

int longestDay(int y, int x){
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	int current = map[y][x];
	map[y][x] = 0;

	ret = 0;
	if(y>0 && map[y-1][x]>current) ret = max(ret, longestDay(y-1, x));
	if(y<N-1 && map[y+1][x]>current) ret = max(ret, longestDay(y+1, x));
	if(x>0 && map[y][x-1]>current) ret = max(ret, longestDay(y, x-1));
	if(x<N-1 && map[y][x+1]>current) ret = max(ret, longestDay(y, x+1));

	map[y][x] = current;
	return ret += 1;
}

int main(){

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	memset(cache, -1, sizeof(int)*500*500);
	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			result = max(result, longestDay(i, j));
	printf("%d\n", result);

	return 0;
}