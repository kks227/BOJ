#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 256;
const int INF = 1000000000;

int N, R[MAX], minR[MAX][MAX], dp[MAX][MAX];

int minRankDiff(int s, int e){
	int &ret = dp[s][e];
	if(ret != -1) return ret;
	if(s == e) return ret = 0;

	ret = INF;
	for(int m=s; m<e; m++)
		ret = min(ret, abs(minR[s][m]-minR[m+1][e]) + minRankDiff(s, m) + minRankDiff(m+1, e));
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", R+i);
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++){
			minR[i][j] = R[i];
			for(int k=i+1; k<=j; k++)
				minR[i][j] = min(minR[i][j], R[k]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minRankDiff(0, N-1));
}