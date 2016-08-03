#include <cstdio>
#include <cstring>
using namespace std;

char P[101], F[101], dp[101][101];

char ls(int p, int f){
	char &ret = dp[p][f];
	if(ret != -1) return ret;
	if(!P[p]) return ret = !F[f];
	if(!F[f]){
		if(P[p] == '*') return ret = ls(p+1, f);
		return ret = 0;
	}

	ret = 0;
	if(P[p] == '*') ret |= ls(p, f+1) | ls(p+1, f);
	else if(P[p] == F[f]) ret |= ls(p+1, f+1);
	return ret;
}

int main(){
	int N;
	scanf("%s %d", P, &N);
	for(int i=0; i<N; i++){
		scanf("%s", F);
		memset(dp, -1, sizeof(dp));
		if(ls(0, 0)) puts(F);
	}
}