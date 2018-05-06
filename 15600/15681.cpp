#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[100000], child[100000];
bool visited[100000];
int s[100000];

int dfs(int curr){
	s[curr] = 1;
	visited[curr] = true;
	for(int next: adj[curr]){
		if(!visited[next]){
			child[curr].push_back(next);
			s[curr] += dfs(next);
		}
	}
	return s[curr];
}

int main(){
	int N, R, Q;
	scanf("%d %d %d", &N, &R, &Q);
	for(int i=0; i<N-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(R-1);
	for(int i=0; i<Q; i++){
		int u;
		scanf("%d", &u);
		printf("%d\n", s[u-1]);
	}
}