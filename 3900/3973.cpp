#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		vector<int> adj[100000];
		scanf("%d", &N);
		for(int i=0; i<N-1; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int S = 0, dist[100000];
		for(int k=0; k<2; k++){
			queue<int> Q;
			Q.push(S);
			fill(dist, dist+N, INF);
			dist[S] = 0;

			while(!Q.empty()){
				int curr = Q.front(); Q.pop();
				for(int next: adj[curr]){
					if(dist[next] == INF){
						dist[next] = dist[curr] + 1;
						Q.push(next);
						S = next;
					}
				}
			}
		}
		printf("%d\n", (dist[S]+1)/2);
	}
}