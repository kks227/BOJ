#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;

class Materials{
public:
	void input(){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	int solve(){
		bool visited[MAX] = {false,};
		int depth[MAX];
		fill(depth, depth+N, -1);
		C = 0;
		for(int i = 0; i < N; ++i){
			if(visited[i]) continue;

			queue<int> Q;
			val[C] = 0;
			Q.push(i);
			depth[i] = 0;
			visited[i] = true;
			for(int j = 0; !Q.empty(); ++j){
				int qSize = Q.size();
				for(int k = 0; k < qSize; ++k){
					int curr = Q.front(); Q.pop();
					val[C] += (j%2 ? -1 : 1);
					for(int next: adj[curr]){
						if(visited[next]){
							if(depth[next] == j) return -1;
						}
						else{
							depth[next] = j+1;
							visited[next] = true;
							Q.push(next);
						}
					}
				}
			}
			if(val[C] < 0) val[C] *= -1;
			++C;
		}

		memset(dp, -1, sizeof(dp));
		int temp = minDiff(0, 0);
		return (N-temp)/2 + temp;
	}

private:
	int N, M, C, val[MAX], dp[MAX+1][MAX+1];
	vector<int> adj[MAX];

	int minDiff(int pos, int diff){
		int &ret = dp[pos][diff];
		if(ret != -1) return ret;
		if(pos == C) return diff;
		return ret = min( minDiff(pos+1, diff+val[pos]), minDiff(pos+1, abs(diff-val[pos])) );
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		Materials solver;
		solver.input();
		printf("%d\n", solver.solve());
	}
}