#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[2000], dp[2000][2000];

bool isPalindrome(int s, int e){
	int &ret = dp[s][e];
	if(ret != -1) return ret;
	if(s == e) return ret = true;
	if(s+1 == e) return ret = (val[s] == val[e]);
	return ret = (val[s] == val[e]) & isPalindrome(s+1, e-1);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	memset(dp, -1, sizeof(dp));
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", isPalindrome(S-1, E-1));
	}
}