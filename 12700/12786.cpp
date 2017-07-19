#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, K, dp[101][21][51];
bool hole[100][21];

int suit(int n, int h, int k){
	int &ret = dp[n][h][k];
	if(ret != -1) return ret;
	if(n == N) return ret = k;

	ret = INF;
	if(hole[n][h]) ret = min(suit(n+1, h, k), ret);
	if(h < 20 && hole[n][h+1]) ret = min(suit(n+1, h+1, k), ret);
	if(h > 1 && hole[n][h-1]) ret = min(suit(n+1, h-1, k), ret);
	if(hole[n][min(h*2, 20)]) ret = min(suit(n+1, min(h*2, 20), k), ret);
	if(k < K){
		for(int i=1; i<=20; i++)
			if(hole[n][i]) ret = min(suit(n+1, i, k+1), ret);
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int M;
		scanf("%d", &M);
		for(int j=0; j<M; j++){
			int H;
			scanf("%d", &H);
			hole[i][H] = true;
		}
	}
	memset(dp, -1, sizeof(dp));
	int result = suit(0, 1, 0);
	printf("%d\n", result < INF ? result : -1);
}