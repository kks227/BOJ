#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 1000;
const int INF = 1000000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N, M, dist[MAX];
		vector<P> adj[MAX];
		scanf("%d %d", &N, &M);
		for(int i = 0; i < M; ++i){
			int A, B, C;
			scanf("%d %d %d", &A, &B, &C);
			adj[A].push_back(P(B, C));
		}
		fill(dist, dist+N, INF);
		dist[0] = 0;

		queue<int> Q;
		bool visited[MAX] = {false,};
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				for(auto &p: adj[j]){
					int next = p.first, d = p.second;
					if(dist[j] != INF && dist[next] > dist[j] + d){
						dist[next] = dist[j] + d;
						if(i == N-1){
							visited[i] = true;
							Q.push(i);
						}
					}
				}
			}
		}

		bool result = (dist[0] < 0);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			if(curr == 0){
				result = true;
				break;
			}
			for(auto &p: adj[curr]){
				int next = p.first;
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		printf("Case #%d: %spossible\n", t, result ? "" : "not ");
	}
}
