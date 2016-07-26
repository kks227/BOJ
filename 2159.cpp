#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, sX, sY, X[100000], Y[100000], offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
long long cache[100000][4];

bool invalid(int x, int y){
	return x<=0 || x>100000 || y<=0 || y>100000;
}

long long minDist(int carried, int pos){
	if(carried == N) return 0;
	long long &ret = cache[carried][pos];
	if(ret != -1) return ret;
	ret = 0x7FFFFFFFFFFFFFFF;
	for(int i=0; i<4; i++){
		int nextX = X[carried] + offset[i][0];
		int nextY = Y[carried] + offset[i][1];
		if(invalid(nextX, nextY)) continue;
		ret = min(ret, minDist(carried+1, i) + abs((carried?X[carried-1]+offset[pos][0]:sX) - nextX) + abs((carried?Y[carried-1]+offset[pos][1]:sY) - nextY));
	}
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &sX, &sY);
	for(int i=0; i<N; i++)
		scanf("%d %d", X+i, Y+i);
	memset(cache, -1, sizeof(cache));
	printf("%lld\n", minDist(0, 0));
}