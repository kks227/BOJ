#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef multiset<int> intSet;

int N, E;
vector<intSet> adj;
vector<bool> visited;

void DFS(int current){
	if(visited[current]) return;
	visited[current] = true;
	for(int next: adj[current])
		DFS(next);
}

void EulerCircuit(int current){
	while(adj[current].size()){
		intSet::iterator iter = adj[current].begin();
		int next = *iter;
		adj[current].erase(iter);
		adj[next].erase(adj[next].find(current));
		EulerCircuit(next);
	}
	printf("%d ", current+1);
}

int main(){
	scanf("%d", &N);
	adj.resize(N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int n;
			scanf("%d", &n);
			if(j<=i) continue;
			for(int k=0; k<n; k++){
				adj[i].insert(j);
				adj[j].insert(i);
			}
			E += n;
		}
	}
	E /= 2;

	visited.resize(N);
	int start;
	for(start=0; start<N && adj[start].empty(); start++);
	if(start<N) DFS(start);
	for(int i=start; i<N; i++){
		if(!visited[i] && !adj[i].empty() || adj[i].size()%2){
			puts("-1");
			return 0;
		}
	}
	if(start<N) EulerCircuit(start);
}