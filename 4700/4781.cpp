#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, c[5000], p[5000], dp[10001];

int maxCalories(int m){
	int &ret = dp[m];
	if(ret != -1) return ret;
	if(m == 0) return ret = 0;

	ret = 0;
	for(int i=0; i<N; i++)
		if(m >= p[i]) ret = max(ret, maxCalories(m-p[i]) + c[i]);
	return ret;
}

int main(){
	while(1){
		int d, f;
		scanf("%d %d.%d", &N, &d, &f);
		M = d*100 + f;
		if(N==0 && M==0) break;

		for(int i=0; i<N; i++){
			scanf("%d %d.%d", c+i, &d, &f);
			p[i] = d*100 + f;
		}
		memset(dp, -1, sizeof(dp));
		int result = 0;
		for(int i=0; i<=M; i++)
			result = max(result, maxCalories(i));
		printf("%d\n", result);
	}
}