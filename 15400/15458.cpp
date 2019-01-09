#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100000;
const int MOD = 1000000007;

int N, K, col[MAX], dp[MAX][4];
vector<int> adj[MAX];

int paint(int curr, int prev, int pc){
	int &ret = dp[curr][pc];
	if(ret != -1) return ret;
	if(col[curr] > 0 && col[curr] == pc) return ret = 0;
	if(prev >= 0 && adj[curr].size() == 1) return (col[curr] > 0 ? 1 : 2);

	if(col[curr] > 0){
		ret = 1;
		for(int next: adj[curr]){
			if(next == prev) continue;
			ret = 1LL*ret * paint(next, curr, col[curr]) % MOD;
		}
	}
	else{
		ret = 0;
		for(int c = 1; c <= 3; ++c){
			if(c == pc) continue;
			int temp = 1;
			for(int next: adj[curr]){
				if(next == prev) continue;
				temp = 1LL*temp * paint(next, curr, c) % MOD;
			}
			ret = (temp + ret) % MOD;
		}
	}
	return ret;
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < K; ++i){
		int u, c;
		scanf("%d %d", &u, &c);
		col[u-1] = c;
	}
	if(N == 1){
		printf("%d\n", col[0] > 0 ? 1 : 3);
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", paint(0, -1, 0));
}