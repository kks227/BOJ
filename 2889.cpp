#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
	int u, v, r;
	Edge(): Edge(-1, -1){}
	Edge(int u1, int v1): u(u1), v(v1), r(-1){}
};

int N, N0, E, E0, C;
vector<Edge> edge;
vector<int> adj[200000], component[100000];
bool visited[200000];
vector<int> path;

inline int difval(int a, int b, int c){ return (a==c ? b : a); }

void DFS(int curr){
	visited[curr] = true;
	component[C].push_back(curr);
	if(curr >= N0) return;

	if(adj[curr].size()%2 == 1){
		edge.push_back(Edge(curr, N));
		adj[curr].push_back(E);
		adj[N].push_back(E);
		E++;
	}
	for(int e: adj[curr]){
		int next = difval(edge[e].u, edge[e].v, curr);
		if(!visited[next]) DFS(next);
	}
}

void EulerCircuit(int curr, int e){
	while(!adj[curr].empty()){
		int ne = adj[curr].back();
		int next = difval(edge[ne].u, edge[ne].v, curr);
		adj[curr].pop_back();
		adj[next].erase(find(adj[next].begin(), adj[next].end(), ne));
		EulerCircuit(next, ne);
	}
	if(e >= 0) path.push_back(e);
}



int main(){
	scanf("%d %d", &N0, &E0);
	for(E=0; E<E0; E++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		edge.push_back(Edge(u, v));
		adj[u].push_back(E);
		adj[v].push_back(E);
	}

	N = N0;
	for(int i=0; i<N0; i++){
		if(!visited[i] && !adj[i].empty()){
			DFS(i);
			N++;
			C++;
		}
	}

	bool fail = false;
	for(int c=0; c<C; c++){
		if(component[c].size() == 1) continue;

		int start = N0 + c;
		bool cycle = true;
		for(int i: component[c]){
			if(adj[i].size() > 2){
				cycle = false;
				break;
			}
		}
		if(cycle){
			if(component[c].size()%2 == 1){
				int added = -1;
				fail = true;
				for(int i: component[c]){
					if(i >= N0){
						added = i;
						fail = false;
						break;
					}
				}
				if(fail) break;
				else start = added;
			}
			else start = component[c][0];
		}
		EulerCircuit(start, -1);
	}

	if(fail) puts("0");
	else{
		int cnt = 0;
		for(int e: path)
			edge[e].r = cnt++ % 2 + 1;
		for(int i=0; i<E0; i++)
			printf("%d\n", edge[i].r);
	}
}