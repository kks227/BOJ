#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 500;
const int MAX_V = MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, K = 0, c[MAX_V][MAX_V] = {0}, d[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
		vector<int> adj[MAX_V];
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			x--; y--;
			c[x][y] = c[y][x] = INF;
			d[x][y] = d[y][x] = 1;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=0; i<N; i++){
			int val;
			scanf("%d", &val);
			if(val == 1){
				K++;
				c[S][i] = 1;
				adj[S].push_back(i);
				adj[i].push_back(S);
			}
		}
		for(int i=0; i<N; i++){
			int val;
			scanf("%d", &val);
			if(val == 1){
				c[i][E] = 1;
				adj[E].push_back(i);
				adj[i].push_back(E);
			}
		}

		int result = 0;
		for(int k=0; k<K; k++){
			int prev[MAX_V], dist[MAX_V];
			fill(prev, prev+MAX_V, -1);
			fill(dist, dist+MAX_V, INF);
			dist[S] = 0;
			queue<int> Q;
			Q.push(S);
			bool inQ[MAX_V] = {0};
			inQ[S] = true;

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for(int next: adj[curr]){
					int temp = (f[curr][next] < 0 ? -1 : 1) * d[curr][next];
					if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr]+temp){
						dist[next] = dist[curr] + temp;
						prev[next] = curr;
						if(!inQ[next]){
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}

			for(int i=E; i!=S; i=prev[i]){
				result += (f[prev[i]][i] < 0 ? -1 : 1) * d[prev[i]][i];
				f[prev[i]][i]++;
				f[i][prev[i]]--;
			}
		}
		printf("%d\n", result);
	}
}