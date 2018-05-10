#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_V = 52;
const int INF = 1000000000;

inline int CtoI(char c){
	if(c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main(){
	int N, c[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
	vector<int> adj[MAX_V];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		char u, v;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		u = CtoI(u); v = CtoI(v);
		c[u][v] = c[v][u] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int total = 0, S = CtoI('A'), E = CtoI('Z');
	while(1){
		int prev[MAX_V];
		fill(prev, prev+MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(c[curr][next]-f[curr][next] > 0 && prev[next] == -1){
					Q.push(next);
					prev[next] = curr;
					if(next == E) break;
				}
			}
		}
		if(prev[E] == -1) break;

		int flow = INF;
		for(int i=E; i!=S; i=prev[i])
			flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
		for(int i=E; i!=S; i=prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		total += flow;
	}
	printf("%d\n", total);
}