#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, score[1000], dp[1000];

int maxWellGroup(int pos){
	if(pos == N) return 0;
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = 0;
	int maxScore = 0, minScore = 10000;
	for(int i=pos; i<N; i++){
		maxScore = max(maxScore, score[i]);
		minScore = min(minScore, score[i]);
		ret = max(ret, maxWellGroup(i+1) + maxScore-minScore);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", score+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxWellGroup(0));
}