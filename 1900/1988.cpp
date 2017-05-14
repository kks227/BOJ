#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, B, H[3000], dp[3001][3000][2];

int nap(int pos, int b, bool suc){
	int &ret = dp[pos][b][suc];
	if(ret != -1) return ret;
	if(pos == N) return ret = 0;

	ret = nap(pos+1, b, false);
	if(b > 0) ret = max(ret, nap(pos+1, b-1, true) + suc*H[pos]);
	return ret;
}

int main(){
	scanf("%d %d", &N, &B);
	for(int i=0; i<N; i++)
		scanf("%d", H+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", nap(0, B, false));
}