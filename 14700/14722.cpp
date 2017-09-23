#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[1000][1000], dp[1000][1000][3];

int milk(int r, int c, int type = 0){
	int &ret = dp[r][c][type];
	if(ret != -1) return ret;
	if(r == N-1 && c == N-1) return ret = (val[r][c] == type);

	ret = 0;
	if(r < N-1){
		ret = max(milk(r+1, c, type), ret);
		if(val[r][c] == type) ret = max(milk(r+1, c, (type+1)%3)+1, ret);
	}
	if(c < N-1){
		ret = max(milk(r, c+1, type), ret);
		if(val[r][c] == type) ret = max(milk(r, c+1, (type+1)%3)+1, ret);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &val[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", milk(0, 0));
}