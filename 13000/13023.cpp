#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool visited[2000];
vector<int> adj[2000];

bool dfs(int curr, int cnt = 1){
	if(cnt == 5) return true;
	visited[curr] = true;
	for(int next: adj[curr])
		if(!visited[next] && dfs(next, cnt+1)) return true;
	visited[curr] = false;
	return false;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool result = false;
	for(int i=0; i<N; i++){
		if(result = dfs(i)) break;
		fill(visited, visited+N, false);
	}
	printf("%d\n", result);
}