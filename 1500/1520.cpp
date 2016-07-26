#include <cstdio>
#include <cstring>
using namespace std;

int M, N;
int map[500][500];
int cache[500][500];

int path(int y, int x){
	int &ret = cache[y][x];
	if(ret != -1) return ret;
	if(y==M-1 && x==N-1) return ret = 1;

	ret = 0;
	if(y > 0 && map[y-1][x] < map[y][x]) ret += path(y-1, x);
	if(y<M-1 && map[y+1][x] < map[y][x]) ret += path(y+1, x);
	if(x > 0 && map[y][x-1] < map[y][x]) ret += path(y, x-1);
	if(x<N-1 && map[y][x+1] < map[y][x]) ret += path(y, x+1);
	return ret;
}

int main(){

	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &map[i][j]);
	memset(cache, -1, sizeof(int)*500*500);
	printf("%d\n", path(0, 0));

	return 0;
}