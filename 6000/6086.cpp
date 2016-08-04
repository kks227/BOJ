#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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

inline int CtoI(char c){
	if(c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main(){
	int N;
	vector<Edge*> adj[52];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		char a, b;
		int c;
		scanf(" %c %c %d", &a, &b, &c);
		a = CtoI(a); b = CtoI(b);
		Edge *e = new Edge(a, b, c);
		adj[a].push_back(e);
		adj[b].push_back(e);
	}

	int total = 0, S = 0, E = 25;
	while(1){
		int prev[52];
		Edge *path[52] = {0};
		fill(prev, prev+52, -1);
		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(auto *e: adj[curr]){
				int next = e->oppo(curr);
				if(e->spare(curr) > 0 && prev[next] == -1){
					Q.push(next);
					prev[next] = curr;
					path[next] = e;
					if(next == E) break;
				}
			}
		}
		if(prev[E] == -1) break;

		int flow = 1000000000;
		for(int i=E; i!=S; i=prev[i])
			flow = min(flow, path[i]->spare(prev[i]));
		for(int i=E; i!=S; i=prev[i])
			path[i]->addFlow(prev[i], flow);
		total += flow;
	}
	printf("%d\n", total);
}