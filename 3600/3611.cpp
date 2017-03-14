#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_V = MAX_N + 2;
const int S = MAX_N;
const int E = MAX_N + 1;

int main(){
	int N, M, d[MAX_N] = {0};
	double c[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
	vector<int> adj[MAX_V];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = c[v][u] = 1;
		d[u]++;
		d[v]++;
	}
	if(M == 0){
		printf("1\n1\n");
		return 0;
	}
	for(int i=0; i<N; i++){
		c[S][i] = M;
		adj[S].push_back(i);
		adj[E].push_back(i);
		adj[i].push_back(S);
		adj[i].push_back(E);
	}

	double lo = 0, hi = M;
	vector<int> result;
	while(hi-lo >= 1.0/N/(N-1)){
		double mid = (lo + hi)/2;
		memset(f, 0, sizeof(f));
		for(int i=0; i<N; i++)
			c[i][E] = M + 2*mid - d[i];

		int prev[MAX_V];
		while(1){
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

			double flow = M;
			for(int i=E; i!=S; i=prev[i])
				flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
			for(int i=E; i!=S; i=prev[i]){
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
		}

		bool over = true;
		vector<int> cut;
		for(int i=0; i<N; i++){
			if(prev[i] != -1){
				over = false;
				cut.push_back(i+1);
			}
		}
		if(over) hi = mid;
		else{
			lo = mid;
			result = cut;
		}
	}
	printf("%d\n", result.size());
	for(int i: result)
		printf("%d\n", i);
}