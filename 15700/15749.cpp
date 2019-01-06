#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 250;
const int IMPOSSIBLE = 1e9;

int N, B, f[MAX], s[MAX], d[MAX], dp[MAX][MAX];

int snow(int pos, int b){
	int &ret = dp[pos][b];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = b;

	ret = IMPOSSIBLE;
	for(int i = 1; b+i < B; ++i)
		if(f[pos] <= s[b+i]) ret = min(snow(pos, b+i), ret);
	for(int i = 1; i <= d[b] && pos+i < N; ++i)
		if(f[pos+i] <= s[b]) ret = min(snow(pos+i, b), ret);
	return ret;
}

int main(){
	scanf("%d %d", &N, &B);
	for(int i = 0; i < N; ++i)
		scanf("%d", f+i);
	for(int i = 0; i < B; ++i)
		scanf("%d %d", s+i, d+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", snow(0, 0));
}