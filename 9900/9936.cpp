#include <cstdio>
#include <algorithm>
using namespace std;
const long long UNDEFINED = -1e18;
const long long IMPOSSIBLE = -1e17;

int N, K, c[1000][3];
long long dp[1001][7][1001];

long long domino(int r, int filled, int k){
	long long &ret = dp[r][filled][k];
	if(ret != UNDEFINED) return ret;
	if(k == 0) return ret = 0;
	if(r == N) return ret = IMPOSSIBLE;

	ret = domino(r+1, 0, k);
	switch(filled){
	case 1:
		ret = max(domino(r+1, 0, k-1) + c[r][1]+c[r][2], ret);
		if(r < N-1){
			ret = max(domino(r+1, 2, k-1) + c[r][1]+c[r+1][1], ret);
			ret = max(domino(r+1, 4, k-1) + c[r][2]+c[r+1][2], ret);
			if(k >= 2)
				ret = max(domino(r+1, 6, k-2) + c[r][1]+c[r][2]+c[r+1][1]+c[r+1][2], ret);
		}
		break;
	case 4:
		ret = max(domino(r+1, 0, k-1) + c[r][0]+c[r][1], ret);
		if(r < N-1){
			ret = max(domino(r+1, 1, k-1) + c[r][0]+c[r+1][0], ret);
			ret = max(domino(r+1, 2, k-1) + c[r][1]+c[r+1][1], ret);
			if(k >= 2)
				ret = max(domino(r+1, 3, k-2) + c[r][0]+c[r][1]+c[r+1][0]+c[r+1][1], ret);
		}
		break;
	case 2:
		if(r < N-1){
			ret = max(domino(r+1, 1, k-1) + c[r][0]+c[r+1][0], ret);
			ret = max(domino(r+1, 4, k-1) + c[r][2]+c[r+1][2], ret);
			if(k >= 2)
				ret = max(domino(r+1, 5, k-2) + c[r][0]+c[r][2]+c[r+1][0]+c[r+1][2], ret);
		}
		break;
	case 3:
		if(r < N-1)
			ret = max(domino(r+1, 4, k-1) + c[r][2]+c[r+1][2], ret);
		break;
	case 6:
		if(r < N-1)
			ret = max(domino(r+1, 1, k-1) + c[r][0]+c[r+1][0], ret);
		break;
	case 5:
		if(r < N-1)
			ret = max(domino(r+1, 2, k-1) + c[r][1]+c[r+1][1], ret);
		break;
	default:
		ret = max(domino(r, 3, k-1) + c[r][0]+c[r][1], ret);
		ret = max(domino(r, 6, k-1) + c[r][1]+c[r][2], ret);
		if(r < N-1){
			for(int i=0; i<3; i++){
				ret = max(domino(r+1, 1<<i, k-1) + c[r][i]+c[r+1][i], ret);
				if(k >= 2){
					ret = max(domino(r+1, 7-(1<<i), k-2) + c[r][0]+c[r][1]+c[r][2]-c[r][i] + c[r+1][0]+c[r+1][1]+c[r+1][2]-c[r+1][i], ret);
					if(i != 1)
						ret = max(domino(r+1, 1<<i, k-2) + c[r][0]+c[r][1]+c[r][2]+c[r+1][i], ret);
				}
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d", &c[i][j]);
	for(int i=0; i<=N; i++)
		for(int j=0; j<7; j++)
			for(int k=0; k<=K; k++)
				dp[i][j][k] = UNDEFINED;
	printf("%lld\n", domino(0, 0, K));
}