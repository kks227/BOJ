#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
const long long INF = 1e18;
typedef tuple<long long, int, int> Edge;

int main(){
	int N, M, need = 0, S = 400, E = 401;
	long long d[200][200], c[402][402] = {0}, f[402][402] = {0};
	vector<int> adj[402];
	scanf("%d %d", &N, &M);
	for(int i=0; i<200; i++)
		for(int j=0; j<200; j++)
			d[i][j] = (i==j ? 0 : INF);
	for(int i=0; i<N; i++){
		int A, B, a = i*2, b = i*2+1;
		scanf("%d %d", &A, &B);
		adj[S].push_back(a); adj[a].push_back(S);
		adj[E].push_back(b); adj[b].push_back(E);
		adj[a].push_back(b); adj[b].push_back(a);
		c[S][a] = A;
		c[b][E] = B;
		c[a][b] = INF;
		need += A;
	}
	for(int i=0; i<M; i++){
		int s, e, t;
		scanf("%d %d %d", &s, &e, &t);
		s--; e--;
		d[s][e] = d[e][s] = min(d[e][s], 1LL*t);
	}

	vector<Edge> edge;
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
			if(d[i][j] < INF)
				edge.push_back(Edge(d[i][j], i, j));
	sort(edge.begin(), edge.end());

	long long result = 0, total = 0;
	for(int k=0; k<=edge.size(); k++){
		while(1){
			int prev[402];
			fill(prev, prev+402, -1);
			queue<int> Q;
			Q.push(S);
			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				for(int next: adj[curr]){
					if(prev[next] == -1 && c[curr][next]-f[curr][next] > 0){
						Q.push(next);
						prev[next] = curr;
					}
				}
			}
			if(prev[E] == -1) break;

			long long flow = INF;
			for(int i=E; i!=S; i=prev[i])
				flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
			for(int i=E; i!=S; i=prev[i]){
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
			total += flow;
		}

		if(total == need){
			printf("%lld\n", result);
			return 0;
		}
		if(k < edge.size()){
			int u, v, a, b;
			long long w;
			tie(w, u, v) = edge[k];
			result = w;
			a = u*2; b = v*2+1;
			adj[a].push_back(b);
			adj[b].push_back(a);
			c[a][b] = INF;
			a = v*2; b = u*2+1;
			adj[a].push_back(b);
			adj[b].push_back(a);
			c[a][b] = INF;
		}
	}
	puts("-1");
}