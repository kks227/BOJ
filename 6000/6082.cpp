#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<int> adj[30000];
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool erased[30000] = {0};
	for(int i=0; i<K; i++){
		int u;
		scanf("%d", &u);
		erased[--u] = true;
		for(int v: adj[u])
			if(v != 0) erased[v] = true;
	}

	queue<int> Q;
	bool visited[30000] = {true,};
	Q.push(0);
	int result = 1;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		for(int v: adj[u]){
			if(!visited[v] && !erased[v]){
				result++;
				visited[v] = true;
				Q.push(v);
			}
		}
	}
	printf("%d\n", N-result);
}