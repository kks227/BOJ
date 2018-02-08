#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A, B, dp[1001][1001];
char S[1001], T[1001];

int modify(int a, int b){
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	if(a == A) return ret = B-b;
	if(b == B) return ret = A-a;

	ret = modify(a+1, b+1) + (S[a] != T[b]);
	ret = min(modify(a+1, b) + 1, ret);
	ret = min(modify(a, b+1) + 1, ret);
	return ret;
}

int main(){
	scanf("%s %s", S, T);
	memset(dp, -1, sizeof(dp));
	A = strlen(S); B = strlen(T);
	printf("%d\n", modify(0, 0));
}