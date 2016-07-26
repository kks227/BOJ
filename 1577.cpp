#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
bool noR[101][101], noT[101][101];
long long cache[101][101];

long long cntPath(int x, int y){
	if(x==N && y==M) return 1;
	long long &ret = cache[x][y];
	if(ret != -1) return ret;
	ret = 0;
	if(x<N && !noR[x][y]) ret = cntPath(x+1, y);
	if(y<M && !noT[x][y]) ret += cntPath(x, y+1);
	return ret;
}

int main(){
	int K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<K; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a==c) noT[a][min(b, d)] = true;
		else noR[min(a, c)][b] = true;
	}
	memset(cache, -1, sizeof(cache));
	printf("%lld\n", cntPath(0, 0));
}