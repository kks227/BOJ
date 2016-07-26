#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, m[100], c[100], dp[100][10001];

int maxMemory(int pos, int cost){
	if(pos==N) return 0;
	int &ret = dp[pos][cost];
	if(ret != -1) return ret;

	ret = maxMemory(pos+1, cost);
	if(c[pos] <= cost) ret = max(ret, maxMemory(pos+1, cost-c[pos]) + m[pos]);
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", m+i);
	for(int i=0; i<N; i++)
		scanf("%d", c+i);
	memset(dp, -1, sizeof(dp));
	for(int i=0; ; i++)
		if(maxMemory(0, i) >= M){
			printf("%d\n", i);
			break;
		}
}