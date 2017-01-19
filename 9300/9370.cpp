#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, K, S[3], D[100]; // S: S,G,H
		vector<P> adj[2000];
		scanf("%d %d %d", &N, &M, &K);
		for(int i=0; i<3; i++){
			scanf("%d", S+i);
			S[i]--;
		}
		for(int i=0; i<M; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			adj[u].push_back(P(v, w));
			adj[v].push_back(P(u, w));
		}
		for(int i=0; i<K; i++){
			scanf("%d", D+i);
			D[i]--;
		}

		int dist[3][2000];
		for(int i=0; i<3; i++){
			bool visited[2000] = {false};
			priority_queue<P, vector<P>, greater<P>> PQ;
			fill(dist[i], dist[i]+N, INF);
			dist[i][S[i]] = 0;
			PQ.push(P(0, S[i]));

			while(!PQ.empty()){
				int curr;
				do{
					curr = PQ.top().second;
					PQ.pop();
				}while(!PQ.empty() && visited[curr]);
				if(visited[curr]) break;
				visited[curr] = true;

				for(auto &p: adj[curr]){
					int next = p.first, d = p.second;
					if(dist[i][next] > dist[i][curr] + d){
						dist[i][next] = dist[i][curr] + d;
						PQ.push(P(dist[i][next], next));
					}
				}
			}
		}

		vector<int> result;
		for(int i=0; i<K; i++){
			if(dist[0][D[i]] == INF) continue;
			if(dist[0][D[i]] >= dist[1][S[2]] + min(dist[0][S[1]]+dist[2][D[i]], dist[0][S[2]]+dist[1][D[i]])) result.push_back(D[i]+1);
		}
		sort(result.begin(), result.end());
		for(int i: result)
			printf("%d ", i);
		puts("");
	}
}