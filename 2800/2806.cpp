#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, dp[1000001][2];
char S[1000001];

// A: pos-1번째까지의 DNA가 모두 A인가(true) / B인가(false)
int mutant(int pos, bool A){
	int &ret = dp[pos][A];
	if(ret != -1) return ret;
	if(pos == N) return ret = !A;

	if(S[pos] == 'A'){
		if(A) ret = min(mutant(pos+1, true), mutant(pos+1, false)+1);
		else ret = min(mutant(pos+1, false)+1, mutant(pos+1, true)+1);
	}
	else{
		if(A) ret = min(mutant(pos+1, true)+1, mutant(pos+1, false)+1);
		else ret = min(mutant(pos+1, false), mutant(pos+1, true)+1);
	}
	return ret;
}

int main(){
	scanf("%d %s", &N, S);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", min(mutant(0, false), mutant(0, true)));
}