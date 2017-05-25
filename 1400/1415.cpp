#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int P_MAX = 500001;

int main(){
	bool np[P_MAX] = {1, 1};
	for(int i=4; i<P_MAX; i+=2)
		np[i] = true;
	for(int i=3; i<P_MAX; i+=2){
		if(np[i]) continue;
		for(long long j=1LL*i*i; j<P_MAX; j+=i*2)
			np[j] = true;
	}

	int N, K, cost[50], cnt[50], sum = 0;
	unordered_map<int, int> M;
	scanf("%d", &N);
	for(int i=0, k; i<N; i++){
		scanf("%d", &k);
		sum += k;
		auto finder = M.find(k);
		if(finder != M.end()) finder->second++;
		else M[k] = 1;
	}
	for(auto p: M){
		cost[K] = p.first;
		cnt[K++] = p.second;
	}

	long long dp[2][P_MAX] = {0};
	for(int i=sum; i>=0; i--){
		if(np[i]) continue;
		int a = K%2;
		dp[a][i] = 1;
	}
	for(int i=K-1; i>=0; i--){
		int a = i%2, b = !a;
		for(int j=sum; j>=0; j--){
			if(dp[b][j] == 0) continue;
			for(int k=0; k<=cnt[i] && j-cost[i]*k>=0; k++)
				dp[a][j-cost[i]*k] += dp[b][j];
		}
		fill(dp[b], dp[b]+P_MAX, 0);
		sum -= cost[i];
	}
	printf("%lld\n", dp[0][0]);
}