#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int MAX_S = 101;
const int MAX_V = MAX_N*MAX_S+2;
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
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, I, G, L, M, R, init;
		vector<Edge*> adj[MAX_V];
		scanf("%d %d %d %d %d", &N, &I, &G, &L, &M);
		init = (I-1)*MAX_S;
		Edge *e = new Edge(S, init, G);
		adj[S].push_back(e);
		adj[init].push_back(e);

		for(int k=0; k<M; k++){
			int i;
			scanf("%d", &i);
			i--;
			for(int j=0; j<=L; j++){
				int curr = i*MAX_S + j;
				e = new Edge(curr, E, INF);
				adj[curr].push_back(e);
				adj[E].push_back(e);
			}
		}
		scanf("%d", &R);
		for(int i=0; i<R; i++){
			int a, b, p, d;
			scanf("%d %d %d %d", &a, &b, &p, &d);
			a--; b--;
			for(int j=0; j+d<=L; j++){
				int curr = a*MAX_S + j, next = b*MAX_S + j+d;
				e = new Edge(curr, next, p);
				adj[curr].push_back(e);
				adj[next].push_back(e);
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<L; j++){
				int curr = i*MAX_S + j, next = curr + 1;
				e = new Edge(curr, next, INF);
				adj[curr].push_back(e);
				adj[next].push_back(e);
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
}