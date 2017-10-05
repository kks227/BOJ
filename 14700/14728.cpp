#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, T, K[100], S[100], dp[101][10001];

int exam(int pos, int t){
	int &ret = dp[pos][t];
	if(pos == N) return ret = 0;

	ret = exam(pos+1, t);
	if(t >= K[pos]) ret = max(exam(pos+1, t-K[pos]) + S[pos], ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &T);
	for(int i=0; i<N; i++)
		scanf("%d %d", K+i, S+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", exam(0, T));
}