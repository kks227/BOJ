#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const char P[3] = {'B', 'L', 'D'};

int N, dp[1500][1500][3];
char S[1501];

int pill(int s, int e, int k){
	int &ret = dp[s][e][k];
	if(ret != -1) return ret;
	if(s > e) return ret = 0;

	ret = 0;
	if(S[s] == P[k]) ret = max(pill(s+1, e, (k+1)%3) + 1, ret);
	if(S[e] == P[k]) ret = max(pill(s, e-1, (k+1)%3) + 1, ret);
	return ret;
}

int main(){
	scanf("%d %s", &N, S);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", pill(0, 3*N-1, 0));
}