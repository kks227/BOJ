#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int val[12], cnt[4], sum[4], result = INF;

void backtrack(int n){
	if(n == 12){
		int M = -INF, m = INF;
		for(int i = 0; i < 4; ++i){
			M = max(sum[i], M);
			m = min(sum[i], m);
		}
		result = min(M-m, result);
		return;
	}

	for(int i = 0; i < 4; ++i){
		if(cnt[i] < 3){
			++cnt[i];
			sum[i] += val[n];
			backtrack(n+1);
			--cnt[i];
			sum[i] -= val[n];
		}
	}
}

int main(){
	for(int i = 0; i < 12; ++i)
		scanf("%d", val+i);
	backtrack(0);
	printf("%d\n", result);
}