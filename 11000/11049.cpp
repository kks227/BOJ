#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, r[500], c[500], dp[500][500];

int minMtp(int first, int last){
	if(first == last) return 0;
	int &ret = dp[first][last];
	if(ret != -1) return ret;
	
	ret = 0x7FFFFFFF;
	for(int i=first+1; i<=last; i++)
		ret = min(ret, minMtp(first, i-1) + minMtp(i, last) + r[first]*r[i]*c[last]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", r+i, c+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", minMtp(0, N-1));
}