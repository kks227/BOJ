#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_V = 2*(MAX_N+1);
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int main(){
	int N, M, c[MAX_V][MAX_V]={0}, f[MAX_V][MAX_V]={0};
	vector<int> adj[MAX_V];
	scanf("%d %d", &N, &M);
	for(int i=MAX_N; i<MAX_N+N; i++){
		scanf("%d", &c[i][E]);
		adj[E].push_back(i);
		adj[i].push_back(E);
	}
	for(int i=0; i<M; i++){
		scanf("%d", &c[S][i]);
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=0; i<M; i++){
		for(int j=MAX_N; j<MAX_N+N; j++){
			scanf("%d", &c[i][j]);
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	int result = 0;
	while(1){
		int prev[MAX_V];
		fill(prev, prev+MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(prev[next] == -1 && c[curr][next]-f[curr][next]){
					prev[next] = curr;
					Q.push(next);
				}
			}
		}
		if(prev[E] == -1) break;

		int flow = INF;
		for(int i=E; i!=S; i=prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for(int i=E; i!=S; i=prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		result += flow;
	}
	printf("%d\n", result);
}