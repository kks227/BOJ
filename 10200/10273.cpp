#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 20000;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, M, val[MAX], dp[MAX], indegree[MAX] = {0,}, prev[MAX];
		vector<P> adj[MAX], adjR[MAX];
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; ++i)
			scanf("%d", val+i);
		for(int i = 0; i < M; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			adj[u].push_back(P(v, w));
			adjR[v].push_back(P(u, w));
		}
		fill(dp, dp+N, -INF);

		queue<int> Q;
		Q.push(0);
		bool visited[MAX] = {true,};
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(auto &p: adj[curr]){
				int next = p.first;
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		for(int i = 0; i < N; ++i){
			if(!visited[i]) continue;
			for(auto &p: adj[i])
				++indegree[p.first];
		}

		Q.push(0);
		dp[0] = val[0];
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(auto &p: adj[curr]){
				int next = p.first, temp = dp[curr] - p.second + val[next];
				if(temp > dp[next]){
					dp[next] = temp;
					prev[next] = curr;
				}
				if(--indegree[next] == 0) Q.push(next);
			}
		}

		int r1 = -INF, r2 = -1;
		for(int i = 0; i < N; ++i){
			if(!visited[i]) continue;
			if(dp[i] > r1){
				r1 = dp[i];
				r2 = i;
			}
		}
		vector<int> path;
		for(int i = r2; i != 0; i = prev[i])
			path.push_back(i);
		path.push_back(0);
		printf("%d %d\n", r1, path.size());
		for(int i = path.size()-1; i >= 0; --i)
			printf("%d ", path[i]+1);
		puts("");
	}
}