#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 300;
const int MAX_V = (MAX_N+1)*2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, c[MAX_V][MAX_V] = {0}, d[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
		vector<int> adj[MAX_V];
		scanf("%d %d\n", &N, &M);
		for(int i=0; i<N; i++){
			c[S][i*2] = 1;
			adj[S].push_back(i*2);
			adj[i*2].push_back(S);
			c[i*2][i*2+1] = 1;
			d[i*2][i*2+1] = -1;
			d[i*2+1][i*2] = 1;
			adj[i*2].push_back(i*2+1);
			adj[i*2+1].push_back(i*2);
			c[i*2+1][E] = 1;
			adj[i*2+1].push_back(E);
			adj[E].push_back(i*2+1);
		}
		for(int i=0; i<M; i++){
			int A, B;
			scanf("%d %d", &A, &B);
			A = (A-1)*2+1;
			B = (B-1)*2;
			c[A][B] = 1;
			adj[A].push_back(B);
			adj[B].push_back(A);
		}

		int result = 0;
		for(int k=0; k<2; k++){
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
				result -= d[prev[i]][i];
				f[prev[i]][i]++;
				f[i][prev[i]]--;
			}
		}
		printf("%d\n", result);
	}
}