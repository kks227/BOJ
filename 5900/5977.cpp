#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const long long INF = 1e18;
typedef pair<long long, int> P;

int main(){
	int N, K, A[100000];
	long long dp[100000] = {0}, temp = INF, sum = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		sum += A[i];
		if(i <= K){
			dp[i] = A[i];
			PQ.push(P(A[i], i));
			if(i >= N-K-1)
				temp = min(dp[i], temp);
		}
	}
	if(N <= K){
		printf("%lld\n", sum);
		return 0;
	}

	for(int i=K+1; i<N; i++){
		while(1){
			if(PQ.top().second >= i-K-1){
				dp[i] = PQ.top().first;
				break;
			}
			PQ.pop();
		}
		dp[i] += A[i];
		PQ.push(P(dp[i], i));
		if(i >= N-K-1) temp = min(dp[i], temp);
	}
	printf("%lld\n", sum - temp);
}