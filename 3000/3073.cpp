#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	while(1){
		int R, C;
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		int cnt[2] = {0}, rpos[2][100], cpos[2][100];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				char ch = getchar();
				if(ch == 'm'){
					rpos[0][cnt[0]] = i;
					cpos[0][cnt[0]] = j;
					cnt[0]++;
				}
				else if(ch == 'H'){
					rpos[1][cnt[1]] = i;
					cpos[1][cnt[1]] = j;
					cnt[1]++;
				}
			}
		}

		int c[202][202] = {0}, d[202][202] = {0}, f[202][202] = {0};
		vector<int> adj[202];
		int S = 200, E = 201;
		for(int i=0; i<cnt[0]; i++){
			int a = i*2, b = i*2+1;
			adj[S].push_back(a);
			adj[a].push_back(S);
			adj[b].push_back(E);
			adj[E].push_back(b);
			c[S][a] = c[b][E] = 1;
			for(int j=0; j<cnt[0]; j++){
				b = j*2+1;
				adj[a].push_back(b);
				adj[b].push_back(a);
				c[a][b] = 1;
				d[a][b] = abs(rpos[0][i]-rpos[1][j]) + abs(cpos[0][i]-cpos[1][j]);
				d[b][a] = -d[a][b];
			}
		}

		int cost = 0;
		for(int i=0; i<cnt[0]; i++){
			int prev[202], dist[202];
			fill(prev, prev+202, -1);
			fill(dist, dist+202, INF);
			dist[S] = 0;
			bool inQ[202] = {false};
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

			for(int j=E; j!=S; j=prev[j]){
				f[prev[j]][j]++;
				f[j][prev[j]]--;
				cost += d[prev[j]][j];
			}
		}
		printf("%d\n", cost);
	}
}