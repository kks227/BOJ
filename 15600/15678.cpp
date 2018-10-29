#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
const long long INF = 1e18;

int main(){
	int N, D, A[100000];
	scanf("%d %d", &N, &D);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	long long dp[100000], result = -INF;
	fill(dp, dp+N, -INF);
	deque<int> DQ;
	for(int i=0; i<N; i++){
		while(!DQ.empty()){
			if(DQ.front() < i-D) DQ.pop_front();
			else break;
		}
		dp[i] = (DQ.empty() || dp[DQ.front()] < 0 ? 0 : dp[DQ.front()]) + A[i];
		while(!DQ.empty()){
			if(dp[DQ.back()] <= dp[i]) DQ.pop_back();
			else break;
		}
		DQ.push_back(i);
		result = max(dp[i], result);
	}
	printf("%lld\n", result);
}