#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, M, K, edge[100000][2], query[200000][2];
	bool erased[100000] = {false,};
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<M; i++){
		scanf("%d %d", &edge[i][0], &edge[i][1]);
		edge[i][0]--; edge[i][1]--;
	}
	for(int i=0; i<K; i++){
		char o;
		scanf(" %c %d", &o, &query[i][1]);
		query[i][1]--;
		query[i][0] = (o == 'E');
		if(!query[i][0]) erased[query[i][1]] = true;
	}

	int dist[1000];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	vector<int> adj[1000];
	for(int i=0; i<M; i++)
		if(!erased[i]) adj[edge[i][0]].push_back(edge[i][1]);
	queue<int> Q;
	Q.push(0);
	for(int i=1; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(dist[next] == INF){
					dist[next] = i;
					Q.push(next);
				}
			}
		}
	}

	int result[200000], R = 0;
	for(int k=K-1; k>=0; k--){
		if(query[k][0]) result[R++] = dist[query[k][1]];
		else{
			int u = edge[query[k][1]][0], v = edge[query[k][1]][1];
			adj[u].push_back(v);
			if(dist[u]+1 < dist[v]){
				dist[v] = dist[u]+1;
				Q.push(v);
				for(int i=dist[v]+1; !Q.empty(); i++){
					int qSize = Q.size();
					for(int j=0; j<qSize; j++){
						int curr = Q.front(); Q.pop();
						for(int next: adj[curr]){
							if(dist[curr]+1 < dist[next]){
								dist[next] = i;
								Q.push(next);
							}
						}
					}
				}
			}
		}
	}
	while(--R >= 0) printf("%d\n", result[R] < INF ? result[R] : -1);
}