#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 5000;

int N;
short dp[MAX][MAX];
char S[MAX+1];

short makeP(int s, int e){
	short &ret = dp[s][e];
	if(ret != -1) return ret;
	if(s == e) return ret = 0;
	if(s+1 == e) return ret = (S[s] != S[e]);

	ret = min(makeP(s+1, e), makeP(s, e-1)) + 1;
	if(S[s] == S[e]) ret = min(makeP(s+1, e-1), ret);
	return ret;
}

int main(){
	scanf("%d %s", &N, S);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", makeP(0, N-1));
}