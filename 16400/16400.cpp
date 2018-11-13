#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 123456789;

int main(){
	int N, P = 1;
	vector<int> p;
	bool np[40001] = {1, 1,};
	p.push_back(2);
	for(int i = 4; i <= 40000; i += 2)
		np[i] = true;
	for(int i = 3; i <= 40000; i += 2){
		if(np[i]) continue;
		++P;
		p.push_back(i);
		for(int j = i*i; j <= 40000; j += i*2)
			np[j] = true;
	}
	scanf("%d", &N);

	vector<int> dp[2];
	dp[0].resize(N+1);
	dp[1].resize(N+1);
	bool t = false;
	dp[!t][0] = 1;
	for(int i = 0; i < P; ++i, t = !t){
		fill(dp[t].begin(), dp[t].end(), 0);
		for(int j = 0; j <= N; ++j){
			dp[t][j] = (0LL + dp[t][j] + dp[!t][j]) % MOD;
			if(j+p[i] <= N)
				dp[!t][j+p[i]] = (0LL + dp[!t][j+p[i]] + dp[!t][j]) % MOD;
		}
	}
	printf("%d\n", dp[!t][N]);
}