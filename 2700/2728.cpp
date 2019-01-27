#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 30;
const int MAX = 1000;

int N, D, cost[MAX_N], dp[MAX_N+1][MAX_N+1][MAX+1];

int combi(int pos, int m, int k){
	int &ret = dp[pos][m][k];
	if(ret != -1) return ret;
	if(pos == N) return ret = (m == pos || cost[m] > k);

	ret = combi(pos+1, m, k);
	if(cost[pos] <= k)
		ret += combi(pos+1, (pos == m ? m+1 : m), k-cost[pos]);
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d %d", &N, &D);
		bool flag = true;
		for(int i = 0; i < N; ++i){
			scanf("%d", cost+i);
			if(cost[i] <= D) flag = false;
		}
		sort(cost, cost+N);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", combi(0, 0, D) - flag);
	}
}