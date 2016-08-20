#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 400;
const int MAX_V = 2*(MAX_N+1);
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

int main(){
	int N, M, c[MAX_V][MAX_V]={0}, d[MAX_V][MAX_V]={0}, f[MAX_V][MAX_V]={0};
	vector<int> adj[MAX_V];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int cnt;
		scanf("%d", &cnt);
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);

		for(int j=0; j<cnt; j++){
			int work, pay;
			scanf("%d %d", &work, &pay);
			work = work-1 + MAX_N;
			c[i][work] = 1;
			d[i][work] = pay;
			d[work][i] = -pay;
			adj[i].push_back(work);
			adj[work].push_back(i);
		}
	}
	for(int i=MAX_N; i<MAX_N+M; i++){
		c[i][E] = 1;
		adj[i].push_back(E);
		adj[E].push_back(i);
	}

	int total = 0, cost = 0;
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
			cost += d[prev[i]][i];
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
		total++;
	}
	printf("%d\n%d\n", total, cost);
}