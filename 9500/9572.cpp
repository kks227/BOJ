#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int INF = 1e9;
typedef pair<int, int> P;

int N, dp[MAX][MAX];
P p[MAX];

int hop(int prev, int curr){
	int &ret = dp[prev][curr];
	if(ret != -1) return ret;
	if(curr == 0 || curr == N-1) return ret = p[curr].second;

	ret = max(hop(prev, curr + (prev < curr ? 1 : -1)), p[curr].second);
	if(prev < curr){
		int next = lower_bound(p, p+N, P(2*p[curr].first-p[prev].first, -INF)) - p;
		if(next < N) ret = max(hop(curr, next) + p[curr].second, ret);
	}
	else{
		int next = upper_bound(p, p+N, P(2*p[curr].first-p[prev].first, INF)) - p;
		if(next > 0) ret = max(hop(curr, next-1) + p[curr].second, ret);
	}
	return ret;
}

int main(){
	int result = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", &p[i].first, &p[i].second);
		result = max(p[i].second, result);
	}
	sort(p, p+N);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(i != j) result = max(hop(i, j) + p[i].second, result);
	printf("%d\n", result);
}