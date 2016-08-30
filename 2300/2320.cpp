#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, len[16], dp[16][1<<16];
char W[16][101];

int maxScore(int pos, int used){
	int &ret = dp[pos][used];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=0; i<N; i++)
		if(!used || !(used & (1<<i)) && W[pos][len[pos]-1] == W[i][0])
			ret = max(ret, maxScore(i, used | (1<<i)) + len[i]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", W[i]);
		len[i] = strlen(W[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxScore(0, 0));
}