#include <cstdio>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, dp[1001];
char map[1001], c[3] = {'B', 'O', 'J'};

int BOJ(int pos, int k){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = 0;
	
	ret = IMPOSSIBLE;
	for(int i=pos+1; i<N; i++)
		if(map[i] == c[(k+1)%3]) ret = min(ret, BOJ(i, (k+1)%3)+(i-pos)*(i-pos));
	return ret;
}

int main(){
	scanf("%d %s", &N, map);
	fill(dp, dp+1001, -1);
	if(BOJ(0, 0) == IMPOSSIBLE) puts("-1");
	else printf("%d\n", BOJ(0, 0));
}