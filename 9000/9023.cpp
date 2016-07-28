#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int town[2][100], C, D, d, dp[100][100];

int training(int i, int j){
	int &ret = dp[i][j];
	if(ret != -1) return ret;
	if(town[0][i] == 0){
		if(town[1][j] == 0) return ret = 0;
		int cnt = 0;
		for(; town[1][j]; j++) cnt++;
		return ret = cnt*(C+d) + D;
	}
	if(town[1][j] == 0){
		int cnt = 0;
		for(; town[0][i]; i++) cnt++;
		return ret = cnt*(C+d) + D;
	}

	ret = 1000000000;
	if(town[0][i] == town[1][j]) ret = training(i+1, j+1) + C;
	else ret = training(i+1, j+1) + C*2;
	for(int cnt=1; town[1][j+cnt-1]; cnt++)
		ret = min(ret, training(i, j+cnt) + cnt*(C+d) + D);
	for(int cnt=1; town[0][i+cnt-1]; cnt++)
		ret = min(ret, training(i+cnt, j) + cnt*(C+d) + D);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d", &C, &D, &d);
		for(int i=0; i<2; i++){
			for(int j=0; ; j++){
				scanf("%d", &town[i][j]);
				if(town[i][j] == 0) break;
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", training(0, 0));
	}
}