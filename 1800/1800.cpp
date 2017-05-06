#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int N, M, K, lo = 0, hi = 0;
	scanf("%d %d %d", &N, &M, &K);
	vector<P> adj[1000];
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
		hi = max(hi, w);
	}

	int dist[1000];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	queue<int> Q;
	Q.push(0);
	for(int d=1; !Q.empty(); d++){
		int curr = Q.front();
		Q.pop();
		for(auto &p: adj[curr]){
			int next = p.first;
			if(dist[next] == INF){
				dist[next] = d;
				Q.push(next);
			}
		}
	}
	if(dist[N-1] == INF){
		puts("-1");
		return 0;
	}
	if(dist[N-1] <= K){
		puts("0");
		return 0;
	}

	while(lo+1 < hi){
		int mid = (lo+hi)/2;

		bool visited[1000][1000] = {1,};
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int curr = Q.front() / 1000, used = Q.front() % 1000;
			Q.pop();
			for(auto &p: adj[curr]){
				int next = p.first, d = p.second;
				if(used < K && !visited[next][used+1]){
					visited[next][used+1] = true;
					Q.push(next*1000 + used+1);
				}
				if(d <= mid && !visited[next][used]){
					visited[next][used] = true;
					Q.push(next*1000 + used);
				}
			}
		}

		bool reachable = false;
		for(int i=0; i<=K; i++)
			reachable |= visited[N-1][i];
		(reachable ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}