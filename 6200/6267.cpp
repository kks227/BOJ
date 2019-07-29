#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int B = 12;
const int MAX_N = 16;
const int MAX = B*MAX_N + 2;
const int S = MAX-2;
const int E = MAX-1;
const int INF = 1e9;

class CrazyBit{
public:
	CrazyBit(){
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
	}

	bool input(){
		int N;
		scanf("%d", &N);
		if(N == 0) return false;

		for(int i = 0; i < 2; ++i){
			bcnt[i] = 0;
			for(int j = 0; j < N; ++j){
				int val;
				scanf("%d", &val);
				for(int b = 0; b < B; ++b){
					if(val%2){
						++bcnt[i];
						if(i == 0) addEdge(S, j*B+b, 1, 0);
						else addEdge(j*B+b, E, 1, 0);
					}
					val /= 2;
				}
			}
		}
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < B; ++j){
				if(i > 0) addEdgeBidir(i*B+j, (i-1)*B+j, INF, 1);
				if(j > 0) addEdgeBidir(i*B+j, i*B+j-1, INF, 1);
			}
		}
		return true;
	}

	int solve(){
		if(bcnt[0] != bcnt[1]) return -1;

		int total = 0, cost = 0;
		while(1){
			bool inQ[MAX] = {false,};
			int prev[MAX], dist[MAX];
			fill(prev, prev+MAX, -1);
			fill(dist, dist+MAX, INF);
			queue<int> Q;
			Q.push(S);
			inQ[S] = true;
			dist[S] = 0;

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for(int next: adj[curr]){
					int temp = (f[curr][next] < 0 ? -1 : 1) * d[curr][next];
					if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr] + temp){
						dist[next] = dist[curr] + temp;
						prev[next] = curr;
						if(!inQ[next]){
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if(prev[E] == -1) break;

			++total;
			for(int i = E; i != S; i = prev[i]){
				cost += (f[prev[i]][i] < 0 ? -1 : 1) * d[prev[i]][i];
				++f[prev[i]][i];
				--f[i][prev[i]];
			}
		}

		if(total < bcnt[0]) return -1;
		return cost;
	}

private:
	int c[MAX][MAX], d[MAX][MAX], f[MAX][MAX], bcnt[2];
	vector<int> adj[MAX];

	void addEdge(int u, int v, int c1, int d1){
		c[u][v] = c1;
		d[u][v] = d1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void addEdgeBidir(int u, int v, int c1, int d1){
		c[u][v] = c[v][u] = c1;
		d[u][v] = d[v][u] = d1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};

int main(){
	while(1){
		CrazyBit solver;
		if(!solver.input()) break;
		int result = solver.solve();
		if(result < 0) puts("Impossible");
		else printf("%d\n", result);
	}
}