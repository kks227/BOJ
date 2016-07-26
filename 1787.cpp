#include <cstdio>
#include <cstring>
using namespace std;

int N, pi[1000000], dp[1000001];
char S[1000001];

int minCommonEdge(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(pi[n-1] == 0) return ret = n;
	return ret = minCommonEdge(pi[n-1]);
}

int main(){
	scanf("%d %s", &N, S);
	int j = 0;
	for(int i=1; i<N; i++){
		while(j > 0 && S[i] != S[j]) j = pi[j-1];
		if(S[i] == S[j]) pi[i] = ++j;
	}
	memset(dp, -1, sizeof(dp));
	long long result = 0;
	for(int i=0; i<N; i++){
		int temp = minCommonEdge(i+1);
		if(temp > 0) result += i+1-temp;
	}
	printf("%lld\n", result);
}