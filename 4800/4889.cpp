#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int N, dp[2001][1001];
char S[2001];

int stable(int pos, int opened){
	int &ret = dp[pos][opened];
	if(ret != -1) return ret;
	if(pos == N) return ret = (opened ? IMPOSSIBLE : 0);

	ret = IMPOSSIBLE;
	if(opened < N/2) ret = stable(pos+1, opened+1) + (S[pos] == '}');
	if(opened > 0) ret = min(stable(pos+1, opened-1) + (S[pos] == '{'), ret);
	return ret;
}

int main(){
	for(int t=1; ; t++){
		scanf("%s", S);
		if(S[0] == '-') break;

		memset(dp, -1, sizeof(dp));
		N = strlen(S);
		printf("%d. %d\n", t, stable(0, 0));
	}
}