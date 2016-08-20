#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 11;
const int MAX_V = 2*(N+1);
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int c[MAX_V][MAX_V]={0}, d[MAX_V][MAX_V]={0}, f[MAX_V][MAX_V]={0};
		vector<int> adj[MAX_V];
		for(int i=0; i<N; i++){
			c[S][i] = c[N+i][E] = 1;
			adj[S].push_back(i);
			adj[i].push_back(S);
			adj[N+i].push_back(E);
			adj[E].push_back(N+i);

			for(int j=N; j<N*2; j++){
				scanf("%d", &d[i][j]);
				if(d[i][j] != 0){
					d[j][i] = d[i][j];
					d[i][j] = -d[i][j];
					c[i][j] = 1;
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		int cost = 0;
		while(1){
			int prev[MAX_V], dist[MAX_V];
			bool inQ[MAX_V] = {0};
			queue<int> Q;
			fill(prev, prev+MAX_V, -1);
			fill(dist, dist+MAX_V, INF);
			dist[S] = 0;
			inQ[S] = true;
			Q.push(S);

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for(int next: adj[curr]){
					if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr]+d[curr][next]){
						dist[next] = dist[curr] + d[curr][next];
						prev[next] = curr;
						if(!inQ[next]){
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if(prev[E] == -1) break;

			for(int i=E; i!=S; i=prev[i]){
				cost -= d[prev[i]][i];
				f[prev[i]][i]++;
				f[i][prev[i]]--;
			}
		}
		printf("%d\n", cost);
	}
}