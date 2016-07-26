#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 17; // roundup log(2, 50000)

int N, M, parent[50000][MAX], depth[50000];
vector<int> adj[50000];
bool visited[50000];

void makeTreeByDFS(int curr){
	visited[curr] = true;
	for(int next: adj[curr])
		if(!visited[next]){
			parent[next][0] = curr;
			depth[next] = depth[curr]+1;
			makeTreeByDFS(next);
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
	memset(parent, -1, sizeof(parent));
	depth[0] = 0;
	makeTreeByDFS(0);
	
	for(int j=0; j<MAX-1; j++)
		for(int i=1; i<N; i++)
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];
			
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;

		if(depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];
		for(int j=0; diff; j++){
			if(diff % 2) u = parent[u][j];
			diff /= 2;
		}
		if(u != v){
			for(int j=MAX-1; j>=0; j--){
				if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		printf("%d\n", u+1);
	}
}