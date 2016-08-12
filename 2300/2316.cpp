#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 800;

struct Edge{
	int u, v, c, f;
	Edge *dual;
	Edge(): Edge(-1, -1, 0){}
	Edge(int u1, int v1, int c1): u(u1), v(v1), c(c1), f(0), dual(nullptr){}
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
	int N, P;
	vector<Edge*> adj[MAX_N];
	scanf("%d %d", &N, &P);
	// 각 정점마다 들어오는 정점/나가는 정점으로 분류
	// 3번 이상의 마을은 한 번만 방문할 수 있기 때문에 이 사이의 간선 용량 = 1
	for(int i=0; i<N; i++){
		Edge *e = new Edge(i*2, i*2+1, 1);
		adj[i*2].push_back(e);
	}
	for(int i=0; i<P; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		Edge *e1 = new Edge(a*2+1, b*2, 1), *e2 = new Edge(b*2+1, a*2, 1);
		e1->dual = e2;
		e2->dual = e1;
		adj[a*2+1].push_back(e1);
		adj[b*2+1].push_back(e2);
	}

	int total = 0, S = 1, E = 2;
	while(1){
		int prev[MAX_N];
		Edge *path[MAX_N] = {0};
		fill(prev, prev+MAX_N, -1);
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

		// 역방향 간선에도 유량 흘려줘야함
		for(int i=E; i!=S; i=prev[i]){
			path[i]->addFlow(prev[i], 1);
			if(path[i]->dual) path[i]->dual->addFlow(prev[i], 1);
		}
		total++;
	}
	printf("%d\n", total);
}