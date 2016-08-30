#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_M = 1000;
const int MAX_N = 100;
const int MAX_V = (MAX_M+1)*MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;

struct Edge{
	int u, v, c, f;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int c1): u(u1), v(v1), c(c1), f(0){}
	int oppo(int s){
		return (s == u ? v : u);
	}
	int spare(int s){
		if(s == u) return c-f;
		return f;
	}
	void addFlow(int s, int nf){
		if(s == u) f += nf;
		else f -= nf;
	}
};

int main(){
	int M, N;
	vector<Edge*> adj[MAX_V];
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++){
		int val;
		scanf("%d", &val);
		Edge *e = new Edge(S, i, val);
		adj[S].push_back(e);
		adj[i].push_back(e);
	}
	for(int i=0; i<N; i++){
		int A, B, W[1000];
		scanf("%d", &A);
		for(int j=0; j<A; j++){
			scanf("%d", W+j);
			W[j]--;
		}
		scanf("%d", &B);

		int buyer = MAX_N*MAX_M + i;
		Edge *e = new Edge(buyer, E, B);
		adj[buyer].push_back(e);
		adj[E].push_back(e);

		if(i < N-1){
			for(int j=0; j<M; j++){
				int curr = MAX_M*i + j, next = MAX_M*(i+1) + j;
				e = new Edge(curr, next, INF);
				adj[curr].push_back(e);
				adj[next].push_back(e);
			}
		}
		for(int jj=0; jj<A; jj++){
			int j = W[jj], curr = MAX_M*i + j;
			e = new Edge(curr, buyer, INF);
			adj[curr].push_back(e);
			adj[buyer].push_back(e);
			if(i == N-1) continue;

			for(int kk=0; kk<A; kk++){
				int k = W[kk], next = MAX_M*(i+1) + k;
				if(j == k) continue;

				e = new Edge(curr, next, INF);
				adj[curr].push_back(e);
				adj[next].push_back(e);
			}
		}
	}

	int total = 0;
	while(1){
		int prev[MAX_V];
		fill(prev, prev+MAX_V, -1);
		Edge *edge[MAX_V] = {nullptr};
		queue<int> Q;
		Q.push(S);

		while(!Q.empty() && prev[E] == -1){
			int curr = Q.front();
			Q.pop();
			for(Edge *e: adj[curr]){
				int next = e->oppo(curr);
				if(e->spare(curr) > 0 && prev[next] == -1){
					prev[next] = curr;
					edge[next] = e;
					Q.push(next);
				}
			}
		}
		if(prev[E] == -1) break;

		int flow = INF;
		for(int i=E; i!=S; i=prev[i])
			flow = min(flow, edge[i]->spare(prev[i]));
		for(int i=E; i!=S; i=prev[i])
			edge[i]->addFlow(prev[i], flow);
		total += flow;
	}
	printf("%d\n", total);
}