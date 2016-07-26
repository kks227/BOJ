#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[3][150000], pSum[3][150001], dp[150000][3][3];

int minDifficulty(int pos, int curr, int prev){
	int &ret = dp[pos][curr][prev];
	if(ret != -1) return ret;

	ret = 1000000000;
	if(curr == prev){
		if(pos < N-3) ret = minDifficulty(pos+1, curr, prev);
		for(int i=0; i<3; i++)
			if(i != curr) ret = min(ret, minDifficulty(pos+1, i, curr));
	}
	else{
		if(pos < N-2) ret = minDifficulty(pos+1, curr, prev);
		for(int i=0; i<3; i++)
			if(i!=curr && i!=prev) ret = min(ret, pSum[i][N]-pSum[i][pos+1]); 
	}
	return ret += val[curr][pos];
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<3; i++)
		for(int j=0; j<N; j++){
			scanf("%d", &val[i][j]);
			pSum[i][j+1] = pSum[i][j] + val[i][j];
		}
	memset(dp, -1, sizeof(dp));
	int result = 1000000000;
	for(int i=0; i<3; i++)
		result = min(result, minDifficulty(0, i, i));
	printf("%d\n", result);
}