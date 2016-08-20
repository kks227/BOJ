#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int INF = 1000000000;

struct Edge{
	int u, v, c, d, f;
	Edge *dual;
	Edge(): Edge(-1, -1, -1, 0){}
	Edge(int u1, int v1, int c1, int d1): u(u1), v(v1), c(c1), d(d1), f(0){}
	int oppo(int s){
		return (s == u ? v : u);
	}
	int spare(int s){
		if(s == u) return c-f;
		return f;
	}
	int distance(int s){
		if(s == u) return d;
		return -d;
	}
	void addFlow(int s, int nf){
		if(s == u) f += nf;
		else f -= nf;
	}
};



int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge*> adj[MAX_N];
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		A--; B--;
		Edge *e1 = new Edge(A, B, 1, C), *e2 = new Edge(B, A, 1, C);
		e1->dual = e2;
		e2->dual = e1;
		adj[A].push_back(e1);
		adj[A].push_back(e2);
		adj[B].push_back(e1);
		adj[B].push_back(e2);
	}

	int cost = 0;
	for(int k=0; k<2; k++){
		int prev[MAX_N], dist[MAX_N], S = 0, E = N-1;
		Edge *path[MAX_N] = {0};
		bool inQ[MAX_N] = {0};
		queue<int> Q;
		fill(prev, prev+MAX_N, -1);
		fill(dist, dist+MAX_N, INF);
		dist[S] = 0;
		inQ[S] = true;
		Q.push(S);

		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for(auto *e: adj[curr]){
				int next = e->oppo(curr);
				if(e->spare(curr) > 0 && dist[next] > dist[curr] + e->distance(curr)){
					dist[next] = dist[curr] + e->distance(curr);
					prev[next] = curr;
					path[next] = e;
					if(!inQ[next]){
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if(prev[E] == -1) break;

		for(int i=E; i!=S; i=prev[i]){
			cost += path[i]->distance(prev[i]);
			path[i]->addFlow(prev[i], 1);
		}
	}
	printf("%d\n", cost);
}