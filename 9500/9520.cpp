#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, dist[1501][1501], dp[1501][1501];

// s나 e가 N이면 아직 시작점, 도착점을 결정 안했다는 뜻
int NPHard(int s, int e, int n){
	int &ret = dp[s][e];
	if(ret != -1) return ret;
	if(n == 0) return ret = dist[s][e];
	return ret = min(NPHard(n-1, e, n-1) + dist[s][n-1], NPHard(s, n-1, n-1) + dist[n-1][e]);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &dist[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", NPHard(N, N, N));
}