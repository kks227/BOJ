#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000001;

int N, S[100], sum[100], dp[101][200001];

int convert(int pos, int remain){
	if(pos == N) return IMPOSSIBLE;
	int &ret = dp[pos][remain];
	if(ret != -1) return ret;
	if(sum[pos]*2 < remain) return ret = IMPOSSIBLE;

	ret = convert(pos+1, remain);
	if(S[pos]*2 >= remain) ret = min(ret, S[pos]*2-remain);
	else ret = min(ret, convert(pos+1, remain-S[pos]*2));
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int E;
		scanf("%d %d", &N, &E);
		for(int i=0; i<N; i++)
			scanf("%d", S+i);
		sum[N-1] = S[N-1];
		for(int i=N-2; i>=0; i--)
			sum[i] = sum[i+1] + S[i];

		memset(dp, -1, sizeof(dp));
		if(E > sum[0]*2) puts("FULL");
		else if(E == 0) puts("0");
		else printf("%d\n", (convert(0, E)+E)/2);
	}
}