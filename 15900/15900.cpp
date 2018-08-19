#include <cstdio>
#include <vector>
using namespace std;

int N, depth[500000];
vector<int> adj[500000], child[500000];
bool visited[500000];

void dfs(int curr, int d){
	visited[curr] = true;
	depth[curr] = d;
	for(int next: adj[curr]){
		if(!visited[next]){
			child[curr].push_back(next);
			dfs(next, d+1);
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	long long cnt = 0;
	for(int i=0; i<N; i++)
		if(child[i].empty()) cnt += depth[i];
	puts(cnt%2 ? "Yes" : "No");
}