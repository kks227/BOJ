#include <cstdio>
#include <cstring>
using namespace std;

char S[31];
int L, dp[30][30];

int palindrome(int s, int e){
	int &ret = dp[s][e];
	if(ret != -1) return ret;
	if(s > e) return ret = 0;
	if(s == e) return ret = 1;
	if(s+1 == e) return ret = (S[s] == S[e]) + 2;

	ret = palindrome(s+1, e) + palindrome(s, e-1) - palindrome(s+1, e-1);
	if(S[s] == S[e]) ret += palindrome(s+1, e-1) + 1;
	return ret;
}

int main(){
	scanf("%s", S);
	L = strlen(S);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", palindrome(0, L-1));
}