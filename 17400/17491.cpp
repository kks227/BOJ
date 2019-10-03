#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 17;
const int INF = 1e9;

int N, x[MAX], y[MAX], dp[MAX][1<<MAX];

int cats(int curr, int visited){
	int &ret = dp[curr][visited];
	if(ret != -1) return ret;
	if(visited == (1<<N)-1) return ret = abs(x[curr]) + abs(y[curr]);

	ret = INF;
	for(int next = 1; next < N; ++next){
		if(visited & 1<<next) continue;
		ret = min(cats(next, visited | 1<<next) + abs(x[curr]-x[next]) + abs(y[curr]-y[next]), ret);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d %d", x+i, y+i);
	++N;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cats(0, 1));
}