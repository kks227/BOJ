#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int V, E, H[5000], outdegree[5000] = {0}, result[5000] = {0};
	vector<int> adj[5000];
	scanf("%d %d", &V, &E);
	for(int i=0; i<V; i++)
		scanf("%d", H+i);
	for(int i=0; i<E; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		if(H[u] < H[v]){
			outdegree[u]++;
			adj[v].push_back(u);
		}
		else if(H[u] > H[v]){
			outdegree[v]++;
			adj[u].push_back(v);
		}
	}

	queue<int> Q;
	for(int i=0; i<V; i++){
		if(outdegree[i] == 0) Q.push(i);
		result[i] = 1;
	}
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			result[next] = max(result[curr]+1, result[next]);
			if(--outdegree[next] == 0) Q.push(next);
		}
	}
	for(int i=0; i<V; i++)
		printf("%d\n", result[i]);
}