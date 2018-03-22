#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const long long LLINF = 1e18;

int main(){
	int B, E, P, N, M;
	scanf("%d %d %d %d %d", &B, &E, &P, &N, &M);
	vector<int> adj[40000];
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int S[3] = {0, 1, N-1}, dist[3][40000];
	for(int k=0; k<3; k++){
		fill(dist[k], dist[k]+N, INF);
		dist[k][S[k]] = 0;
		queue<int> Q;
		Q.push(S[k]);
		for(int i=1; !Q.empty(); i++){
			int qSize = Q.size();
			for(int j=0; j<qSize; j++){
				int curr = Q.front(); Q.pop();
				for(int next: adj[curr]){
					if(dist[k][next] == INF){
						dist[k][next] = i;
						Q.push(next);
					}
				}
			}
		}
	}

	long long result = LLINF;
	for(int i=0; i<N; i++)
		result = min(1LL*B*dist[0][i] + 1LL*E*dist[1][i] + 1LL*P*dist[2][i], result);
	printf("%lld\n", result);
}