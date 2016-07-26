#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, M, dp[10000][150];
bool unstable[10000];

int minJump(int pos, int prevJ){
	if(pos == N-1) return 0;
	int &ret = dp[pos][prevJ];
	if(ret != -1) return ret;

	ret = IMPOSSIBLE;
	for(int k=-1; k<=1; k++){
		int nextPos = pos + prevJ + k;
		if(prevJ+k > 0 && nextPos < N && !unstable[nextPos])
			ret = min(ret, minJump(nextPos, prevJ+k));
	}
	if(ret != IMPOSSIBLE) ret++;
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int pos;
		scanf("%d", &pos);
		unstable[pos-1] = true;
	}
	memset(dp, -1, sizeof(dp));
	int result = minJump(0, 0);
	printf("%d\n", result != IMPOSSIBLE ? result : -1);
}