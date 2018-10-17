#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
	int N, Q, H[1000000];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", H+i);
	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q){
		int K, dp[1000000];
		scanf("%d", &K);
		deque<int> DQ;
		dp[0] = 0;
		DQ.push_back(0);
		for(int i = 1; i < N; ++i){
			while(DQ.front() < i-K) DQ.pop_front();
			dp[i] = dp[DQ.front()] + (H[DQ.front()] <= H[i]);
			while(!DQ.empty()){
				int j = DQ.back();
				if(dp[j] > dp[i] || dp[j] == dp[i] && H[j] <= H[i]) DQ.pop_back();
				else break;
			}
			DQ.push_back(i);
		}
		printf("%d\n", dp[N-1]);
	}
}