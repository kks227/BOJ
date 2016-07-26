#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000000

int N, M, map[50][50], cache[50][50];
bool visited[50][50] = {0};
int yOffset[4] = {-1, 0, 1, 0};
int xOffset[4] = {0, 1, 0, -1};

bool inRange(int y, int x){
	return y>=0 && y<N && x>=0 && x<M;
}

int maxGame(int y, int x){
	if(visited[y][x]) return INF;
	int &ret = cache[y][x];
	if(ret != -1) return ret;

	visited[y][x] = true;
	ret = 1;
	int temp, yNext, xNext;
	for(int i=0; i<4; i++){
		yNext = y + yOffset[i]*map[y][x];
		xNext = x + xOffset[i]*map[y][x];
		if(inRange(yNext, xNext) && map[yNext][xNext]){
			temp = maxGame(yNext, xNext);
			if(temp == INF) return INF;
			ret = max(ret, temp+1);
		}
	}
	visited[y][x] = false;
	return ret;
}

int main(){

	char c;
	scanf("%d %d", &N, &M);
	memset(cache, -1, sizeof(int)*50*50);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++){
			c = getchar();
			if(c == 'H') map[i][j] = 0;
			else map[i][j] = c-'0';
		}
	}
	int result = maxGame(0, 0);
	if(result == INF) result = -1;
	printf("%d\n", result);

	return 0;
}