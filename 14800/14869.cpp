#include <cstdio>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main() {
	int N, M, S, E, T, cost[3000][6000] = {0}, except[3000], pSum[3000][6001] = { 0 };
	scanf("%d %d %d %d %d", &N, &M, &S, &E, &T);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &cost[i][j]);
			pSum[i][j+1] = pSum[i][j] + cost[i][j];
		}
		for(int j = M; j < M+S; j++)
			pSum[i][j+1] = pSum[i][j];
	}
	for(int i = 0; i < N; i++) {
		scanf("%d", except + i);
		except[i]--;
	}

	int dp[3000][6000];
	deque<P> DQ[3000];
	for(int i = 0; i < N; i++)
		fill(dp[i], dp[i] + M+S, INF);
	for(int j = 0; j < M+S; j++) {

		int j0 = j - S;
		if(j0 >= 0) {
			P temp[3000];
			for(int i = 0; i < N; i++)
				temp[i] = P(dp[i][j0], i);
			sort(temp, temp + N);
			for(int i = 0; i < N; i++) {
				for(int k = 0; ; k++) {
					int val = temp[k].first, vi = temp[k].second;
					if(val == INF) break;
					if(vi != i && vi != except[i]) {
						val -= pSum[i][j0+1];
						while (!DQ[i].empty() && DQ[i].back().first > val) DQ[i].pop_back();
						DQ[i].push_back(P(val, j0));
						break;
					}
				}
			}
		}

		for(int i = 0; i < N; i++) {
			if(j >= S-1 && j < E) dp[i][j] = pSum[i][j+1];
			while(!DQ[i].empty() && DQ[i].front().second < j-E)
				DQ[i].pop_front();
			if(!DQ[i].empty())
				dp[i][j] = min(DQ[i].front().first + pSum[i][j+1] + T, dp[i][j]);
		}
	}

	int result = INF;
	for(int i = 0; i < N; i++)
		for(int j = M-1; j < M+S; j++)
			result = min(dp[i][j], result);
	printf("%d\n", result);
}