#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, D, A[100000], maxVal = -INF;
	scanf("%d %d", &N, &D);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		maxVal = max(A[i], maxVal);
	}
	long long dp[100000], result = maxVal;
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