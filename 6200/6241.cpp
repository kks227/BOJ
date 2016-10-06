#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_V = MAX_N*4+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int N, F, D, level[MAX_V], work[MAX_V];
char c[MAX_V][MAX_V], f[MAX_V][MAX_V];
vector<int> adj[MAX_V];

inline void makeEdge(int u, int v){
	c[u][v] = 1;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool bfs(){
	fill(level, level+MAX_V, -1);
	level[S] = 0;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(int next: adj[curr]){
			if(level[next] == -1 && c[curr][next]-f[curr][next] > 0){
				level[next] = level[curr] + 1;
				Q.push(next);
			}
		}
	}
	return level[E] != -1;
}

bool dfs(int curr, int dest){
	if(curr == dest) return true;
	for(int &i=work[curr]; i<adj[curr].size(); i++){
		int next = adj[curr][i];
		if(level[next] == level[curr]+1 && c[curr][next]-f[curr][next] > 0){
			if(dfs(next, dest)){
				f[curr][next]++;
				f[next][curr]--;
				return true;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d", &N, &F, &D);
	for(int i=0; i<F; i++)
		makeEdge(S, i);
	for(int i=0; i<D; i++)
		makeEdge(MAX_N+i, E);
	for(int i=0; i<N; i++){
		int Fi, Di;
		scanf("%d %d", &Fi, &Di);
		for(int j=0; j<Fi; j++){
			int val;
			scanf("%d", &val);
			makeEdge(val-1, MAX_N*2+i);
		}
		for(int j=0; j<Di; j++){
			int val;
			scanf("%d", &val);
			makeEdge(MAX_N*3+i, MAX_N+val-1);
		}
		makeEdge(MAX_N*2+i, MAX_N*3+i);
	}

	int total = 0;
	while(bfs()){
		fill(work, work+MAX_V, 0);
		while(1){
			if(dfs(S, E)) total++;
			else break;
		}
	}
	printf("%d\n", total);
}