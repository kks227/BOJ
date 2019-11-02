#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 200;
const int MAX = MAX_N*2 + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9;

int c[MAX][MAX], d[MAX][MAX], f[MAX][MAX];
vector<int> adj[MAX];

inline void makeEdge(int u, int v, int c1, int d1){
	c[u][v] = c1;
	d[u][v] = d1;
	d[v][u] = -d1;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int m, a, b, k;
		scanf("%d %d %d %d", &m, &a, &b, &k);
		--m; --a; --b;
		makeEdge(S, i, 1, 0);
		makeEdge(MAX_N+i, E, 1, 0);
		for(int j = a; j <= b; ++j)
			makeEdge(i, MAX_N+j, 1, abs(m-j)*k);
	}

	int total = 0, result = 0;
	while(1){
		int dist[MAX], prev[MAX];
		bool inQ[MAX] = {false,};
		queue<int> Q;
		fill(prev, prev + MAX, -1);
		fill(dist, dist + MAX, INF);
		Q.push(S);
		inQ[S] = true;
		dist[S] = 0;
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			inQ[curr] = false;
			for(int next: adj[curr]){
				if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]){
					prev[next] = curr;
					dist[next] = dist[curr] + d[curr][next];
					if(!inQ[next]){
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if(prev[E] == -1) break;

		for(int i = E; i != S; i = prev[i]){
			++f[prev[i]][i];
			--f[i][prev[i]];
			result += d[prev[i]][i];
		}
		++total;
	}
	if(total < N) puts("NIE");
	else printf("%d\n", result);
}