#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

char S[1001], P[1001];
int Slen, Plen, dp[1000];

int minCopy(int pos){
	if(pos == Plen) return 0;
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = IMPOSSIBLE;
	for(int i=0; i<Slen; i++){
		if(S[i] != P[pos]) continue;
		int j;
		for(j=0; i+j<Slen && pos+j<Plen && S[i+j]==P[pos+j]; j++);
		ret = min(ret, minCopy(pos+j) + 1);
	}
	return ret;
}

int main(){
	scanf("%s %s", S, P);
	Slen = strlen(S);
	Plen = strlen(P);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minCopy(0));
}