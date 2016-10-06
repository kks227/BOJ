#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 400;
const int INF = 1000000000;

int main(){
	int N, M, S, E, c[MAX][MAX] = {0}, f[MAX][MAX] = {0};
	vector<int> adj[MAX];
	scanf("%d %d %d %d", &N, &M, &S, &E);
	S = S*2-2;
	E = E*2-1;
	for(int i=0; i<N; i++){
		scanf("%d", &c[i*2][i*2+1]);
		adj[i*2].push_back(i*2+1);
		adj[i*2+1].push_back(i*2);
	}
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		c[u*2+1][v*2] = c[v*2+1][u*2] = INF;
		adj[u*2+1].push_back(v*2);
		adj[v*2].push_back(u*2+1);
		adj[v*2+1].push_back(u*2);
		adj[u*2].push_back(v*2+1);
	}

	while(1){
		int prev[MAX];
		fill(prev, prev+MAX, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty() && prev[E] == -1){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(prev[next] == -1 && c[curr][next]-f[curr][next] > 0){
					prev[next] = curr;
					Q.push(next);
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
	}

	bool visited[MAX] = {0};
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		for(int next: adj[curr]){
			if(!visited[next] && c[curr][next]-f[curr][next] > 0){
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	for(int i=0; i<N; i++)
		if(visited[i*2] && !visited[i*2+1]) printf("%d ", i+1);
}