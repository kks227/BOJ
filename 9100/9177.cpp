#include <cstdio>
#include <cstring>
using namespace std;

char A[201], B[201], C[401], dp[201][201];

char shuffle(int a, int b){
	char &ret = dp[a][b];
	if(ret != -1) return ret;
	if(!A[a] && !B[b]) return ret = 1;

	ret = 0;
	if(A[a] && A[a] == C[a+b]) ret |= shuffle(a+1, b);
	if(B[b] && B[b] == C[a+b]) ret |= shuffle(a, b+1);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%s %s %s", A, B, C);
		memset(dp, -1, sizeof(dp));
		printf("Data set %d: %s\n", t, shuffle(0, 0) ? "yes" : "no");
	}
}