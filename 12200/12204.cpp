#include <cstdio>
#include <cstring>
using namespace std;

int N, K, dp[21][21];

int paren(int pos, int opened){
	int &ret = dp[pos][opened];
	if(ret != -1) return ret;
	if(N-pos == opened) return ret = 1;
	if(N-pos < opened) return ret = 0;
	if(pos == N) return ret = 0;

	ret = paren(pos+1, opened+1);
	if(opened > 0) ret += paren(pos+1, opened-1);
	return ret;
}

void trace(int pos, int opened, int k){
	if(pos == N){
		puts("");
		return;
	}

	int pivot = paren(pos+1, opened+1);
	if(pivot <= k){
		putchar(')');
		trace(pos+1, opened-1, k-pivot);
	}
	else{
		putchar('(');
		trace(pos+1, opened+1, k);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d %d", &N, &K);
		N *= 2;
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: ", t);
		if(paren(0, 0) < K) puts("Doesn't Exist!");
		else trace(0, 0, K-1);
	}
}