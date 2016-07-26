#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, L1, L2, S1, S2, dp[100000][2];
int pass[99999][2], dribble[99999][2];

int easiest(int pos, int sn){
	int &ret = dp[pos][sn];
	if(ret != -1) return ret;
	if(pos == N-1) return ret = (sn ? S2 : S1);
	return ret = min(easiest(pos+1, sn)+dribble[pos][sn], easiest(pos+1, !sn)+pass[pos][sn]);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d %d %d", &N, &L1, &L2, &S1, &S2);
		for(int i=0; i<N-1; i++)
			scanf("%d", &pass[i][0]);
		for(int i=0; i<N-1; i++)
			scanf("%d", &dribble[i][0]);
		for(int i=0; i<N-1; i++)
			scanf("%d", &pass[i][1]);
		for(int i=0; i<N-1; i++)
			scanf("%d", &dribble[i][1]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", min(easiest(0, 0)+L1, easiest(0, 1)+L2));
	}
}