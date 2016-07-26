#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = -1000000000;

int N, S, M, V[100], dp[100][1001];

int maxVolume(int pos, int v){
	if(pos == N) return v;
	int &ret = dp[pos][v];
	if(ret != -1) return ret;

	ret = IMPOSSIBLE;
	if(v-V[pos] >= 0) ret = max(ret, maxVolume(pos+1, v-V[pos]));
	if(v+V[pos] <= M) ret = max(ret, maxVolume(pos+1, v+V[pos]));
	return ret;
}

int main(){
	scanf("%d %d %d", &N, &S, &M);
	for(int i=0; i<N; i++)
		scanf("%d", V+i);
	memset(dp, -1, sizeof(dp));
	int result = maxVolume(0, S);
	printf("%d\n", result!=IMPOSSIBLE ? result : -1);
}