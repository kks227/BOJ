#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX_V = MAX_N*MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, map[MAX_N][MAX_N], sum = 0, c[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				scanf("%d", &map[i][j]);
				sum += map[i][j];
			}
		}
		vector<int> adj[MAX_V];
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				int curr = i*MAX_N+j;
				if(i%2 == j%2){
					adj[S].push_back(curr);
					adj[curr].push_back(S);
					c[S][curr] = map[i][j];

					for(int d=0; d<4; d++){
						int ni = i+roff[d];
						int nj = j+coff[d];
						if(ni<0 || ni>=N || nj<0 || nj>=M) continue;

						int next = ni*MAX_N+nj;
						adj[curr].push_back(next);
						adj[next].push_back(curr);
						c[curr][next] = INF;
					}
				}
				else{
					adj[E].push_back(curr);
					adj[curr].push_back(E);
					c[curr][E] = map[i][j];
				}
			}
		}

		int total = 0;
		while(1){
			int prev[MAX_V];
			fill(prev, prev+MAX_V, -1);
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
			total += flow;
		}
		printf("%d\n", sum-total);
	}
}