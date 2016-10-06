#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_V = (MAX_N+1)*2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, L = 0, c[MAX_V][MAX_V] = {0};
		bool A[MAX_N] = {false}, B[MAX_N] = {false}; // ally, bordering
		vector<int> adj[MAX_V];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &c[S][i*2]);
			if(c[S][i*2] > 0){
				L += c[S][i*2];
				A[i] = true;
				adj[S].push_back(i*2);
				adj[i*2].push_back(S);
				adj[i*2+1].push_back(E);
				adj[E].push_back(i*2+1);
				c[i*2][i*2+1] = INF;
				adj[i*2].push_back(i*2+1);
				adj[i*2+1].push_back(i*2);
			}
		}

		char map[MAX_N][MAX_N];
		for(int i=0; i<N; i++){
			getchar();
			for(int j=0; j<N; j++)
				map[i][j] = getchar();
		}
		for(int i=0; i<N; i++){
			if(!A[i]) continue;
			for(int j=i+1; j<N; j++){
				if(A[j] && map[i][j] == 'Y'){
					c[i*2][j*2+1] = c[j*2][i*2+1] = INF;
					adj[i*2].push_back(j*2+1);
					adj[j*2+1].push_back(i*2);
					adj[j*2].push_back(i*2+1);
					adj[i*2+1].push_back(j*2);
				}
			}
		}
		int acnt = 0, bcnt = 0;
		for(int i=0; i<N; i++){
			if(!A[i]) continue;
			for(int j=0; j<N; j++){
				if(map[i][j] == 'Y' && !A[j]){
					B[i] = true;
					break;
				}
			}
			(B[i] ? bcnt : acnt)++;
		}

		int lo = 1, hi = L+1;
		while(lo+1 < hi){
			int mid = (lo+hi)/2, f[MAX_V][MAX_V] = {0};
			for(int i=0; i<N; i++)
				c[i*2+1][E] = (B[i] ? mid : 1);

			int total = 0, dest = acnt + bcnt*mid;
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
			(total == dest ? lo : hi) = mid;
		}
		printf("%d\n", lo);
	}
}