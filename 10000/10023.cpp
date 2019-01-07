#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;

int B, V[20], dp[21][100001];

int moo(int pos, int k){
	int &ret = dp[pos][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = 0;
	if(pos == B) return ret = IMPOSSIBLE;

	ret = moo(pos+1, k);
	if(k >= V[pos]) ret = min(moo(pos, k-V[pos])+1, ret);
	return ret;
}

int main(){
	int N, X[100];
	scanf("%d %d", &N, &B);
	for(int i = 0; i < B; ++i)
		scanf("%d", V+i);
	for(int i = 0; i < N; ++i)
		scanf("%d", X+i);
	memset(dp, -1, sizeof(dp));

	int result = 0;
	for(int i = 0, j = 0; i < N; ++i){
		if(j > X[i]){
			puts("-1");
			return 0;
		}
		if(j < X[i]){
			int temp = moo(0, X[i]-j);
			if(temp == IMPOSSIBLE){
				puts("-1");
				return 0;
			}
			result += temp;
		}
		j = max(X[i]-1, 0);
	}
	printf("%d\n", result);
}