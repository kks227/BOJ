#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, val[100], dp[100][101];

int maxLec(int pos, int limit){
	if(pos == N) return 0;
	int &ret = dp[pos][limit];
	if(ret != -1) return ret;
	ret = maxLec(pos+1, limit);
	if(val[pos] <= limit) ret = max(ret, maxLec(pos+1, limit-val[pos])+1);
	return ret;
}

int main(){
	int M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int P, L, put[100];
		scanf("%d %d", &P, &L);
		for(int j=0; j<P; j++)
			scanf("%d", put+j);
		if(P < L) val[i] = 1;
		else{
			sort(put, put+P);
			val[i] = put[P-L];
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxLec(0, M));
}