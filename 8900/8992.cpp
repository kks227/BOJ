#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N[2], x1[2][200], y1[2][200], x2[2][200], y2[2][200], w[2][200];
		scanf("%d %d", N, N+1);
		for(int i=0; i<2; i++){
			for(int j=0; j<N[i]; j++){
				scanf("%d %d %d %d %d", &x1[i][j], &y1[i][j], &x2[i][j], &y2[i][j], &w[i][j]);
				if(x1[i][j] > x2[i][j]) swap(x1[i][j], x2[i][j]);
				if(y1[i][j] > y2[i][j]) swap(y1[i][j], y2[i][j]);
			}
		}

		int c[402][402] = {0}, d[402][402] = {0}, f[402][402] = {0};
		vector<int> adj[402];
		int S = 400, E = 401;
		for(int i=0; i<N[0]; i++){
			int a = i*2;
			adj[S].push_back(a);
			adj[a].push_back(S);
			c[S][a] = 1;
			for(int j=0; j<N[1]; j++){
				if(x1[1][j] < x1[0][i] || x2[0][i] < x1[1][j]) continue;
				if(y2[1][j] < y1[0][i] || y1[0][i] < y1[1][j]) continue;

				int b = j*2+1;
				adj[a].push_back(b);
				adj[b].push_back(a);
				c[a][b] = 1;
				d[a][b] = -w[0][i]*w[1][j];
				d[b][a] = -d[a][b];
			}
		}
		for(int i=0; i<N[1]; i++){
			int b = i*2+1;
			adj[b].push_back(E);
			adj[E].push_back(b);
			c[b][E] = 1;
		}

		int total = 0, cost = 0;
		for(int i=0; i<N[0]; i++){
			int prev[402], dist[402];
			fill(prev, prev+402, -1);
			fill(dist, dist+402, INF);
			dist[S] = 0;
			bool inQ[402] = {false};
			inQ[S] = true;
			queue<int> Q;
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
							inQ[next] = true;
							Q.push(next);
						}
					}
				}
			}
			if(prev[E] == -1) break;

			total++;
			for(int j=E; j!=S; j=prev[j]){
				f[prev[j]][j]++;
				f[j][prev[j]]--;
				cost += d[prev[j]][j];
			}
		}
		printf("%d %d\n", total, -cost);
	}
}