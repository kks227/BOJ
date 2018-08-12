#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int N, M, dp[1001][1001];
P A[1000];

int tour(int pos, int lastDay){
	int &ret = dp[pos][lastDay];
	if(ret != -1) return ret;
	if(pos == M) return ret = N-lastDay;
	if(lastDay >= A[pos].first) return ret = tour(pos+1, lastDay);
	return ret = min(
		tour(pos+1, lastDay),
		max(A[pos].first-lastDay-1, tour(pos+1, A[pos].second))
	);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		A[i] = P(a, b);
	}
	sort(A, A+M);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", tour(0, 0));
}