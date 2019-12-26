#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
const int INF = 1e9;

int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, dp[MAX+1];

int seg(int n){
	int &ret = dp[n];
	if(ret != -INF) return ret;
	if(n == 0) return ret = 0;
	if(n == 1) return ret = -INF + 1;
	for(int i = 0; i < 10; ++i)
		if(cost[i] <= n) ret = max(seg(n-cost[i]) + i, ret);
	return ret;
}#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2000000;
const int INF = 1e9;

int N, c[100], dp1[MAX], dp2[MAX];

int solve1(int n){
	int &ret = dp1[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;
	if(n < c[1]) return ret = n;
	ret = INF;
	for(int i = 1; i < N && n >= c[i]; ++i)
		ret = min(solve1(n-c[i]) + 1, ret);
	return ret;
}

int solve2(int n){
	int &ret = dp2[n];
	if(ret != -1) return ret;
	if(n == 0) return ret = 0;
	if(n < c[1]) return ret = n;
	int i = upper_bound(c, c+N, n) - c;
	return ret = solve2(n-c[--i]) + 1;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", c+i);
	fill(dp1, dp1+MAX, -1);
	fill(dp2, dp2+MAX, -1);
	for(int i = c[N-1] + c[N-2]; i > 0; --i){
		if(solve1(i) != solve2(i)){
			puts("non-canonical");
			return 0;
		}
	}
	puts("canonical");
}

int main(){
	int N;
	scanf("%d", &N);
	fill(dp, dp+N+1, -INF);
	printf("%d\n", seg(N));
}