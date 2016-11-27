#include <cstdio>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int N, M, S[100], dp[10001];

int zzazang(int n){
	int &ret = dp[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;

	ret = IMPOSSIBLE;
	for(int i=0; i<M; i++){
		if(S[i] <= n) ret = min(ret, zzazang(n-S[i])+1);
		for(int j=0; j<M; j++)
			if(i != j && S[i]+S[j] <= n) ret = min(ret, zzazang(n-S[i]-S[j])+1);
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++)
		scanf("%d", S+i);
	fill(dp, dp+10001, -1);

	int result = zzazang(N);
	printf("%d\n", result==IMPOSSIBLE ? -1 : result);
}