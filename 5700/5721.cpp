#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int M, N, C[100000], maxC[100000], dp1[100000], dp2[100000];

int maxCandyRow(int c){
	if(c >= N) return 0;
	int &ret = dp2[c];
	if(ret != -1) return ret;

	ret = C[c] + maxCandyRow(c+2);
	if(c+1 < N) ret = max(ret, C[c+1] + maxCandyRow(c+3));
	return ret;
}

int maxCandy(int r){
	if(r >= M) return 0;
	int &ret = dp1[r];
	if(ret != -1) return ret;

	ret = maxC[r] + maxCandy(r+2);
	if(r+1 < M) ret = max(ret, maxC[r+1] + maxCandy(r+3));
	return ret;
}

int main(){
	while(1){
		scanf("%d %d", &M, &N);
		if(M==0 && N==0) break;

		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				scanf("%d", C+j);
				dp2[j] = -1;
			}
			maxC[i] = maxCandyRow(0);
		}
		memset(dp1, -1, sizeof(dp1));
		printf("%d\n", maxCandy(0));
	}
}