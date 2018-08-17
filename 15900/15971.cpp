#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int N, S, E, dist[100000], bridge = 0;
vector<P> adj[100000];

bool dfs(int curr, int prev){
	if(curr == E) return true;

	bool result = false;
	for(auto &p: adj[curr]){
		int next = p.first, d = p.second;
		if(next == prev) continue;
		dist[next] = dist[curr] + d;
		if(dfs(next, curr)){
			result = true;
			bridge = max(d, bridge);
		}
	}
	return result;
}

int main(){
	scanf("%d %d %d", &N, &S, &E);
	S--; E--;
	for(int i=0; i<N-1; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}
	dfs(S, -1);
	printf("%d\n", dist[E]-bridge);
}