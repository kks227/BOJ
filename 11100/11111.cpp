#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX_V = MAX_N*MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int val[6][6] = {
	{10, 8, 7, 5, 0, 1},
	{8, 6, 4, 3, 0, 1},
	{7, 4, 3, 2, 0, 1},
	{5, 3, 2, 2, 0, 1},
	{0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 0}
};

struct Edge{
	int to, c, d, f;
	Edge *dual;
	Edge(): Edge(-1, 0, 0){}
	Edge(int to1, int c1, int d1): to(to1), c(c1), d(d1), f(0), dual(nullptr){}
	int spare(){ return c-f; }
	void addFlow(int f1){ f += f1; dual->f -= f1; }
};

vector<Edge*> edge;
vector<Edge*> adj[MAX_V];

inline void makeEdge(int u, int v, int c, int d){
	Edge *e1 = new Edge(v, c, d), *e2 = new Edge(u, 0, -d);
	e1->dual = e2; e2->dual = e1;
	edge.push_back(e1);
	edge.push_back(e2);
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}

inline int node(int r, int c){ return r*MAX_N+c; }



int main(){
	int N, M, grade[MAX_N][MAX_N];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			grade[i][j] = getchar() - 'A';
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			int currNode = node(i, j);
			makeEdge(currNode, E, 1, 0);
			if(i%2 == j%2){
				makeEdge(S, currNode, 1, 0);
				for(int k=0; k<4; k++){
					int ni = i + roff[k];
					int nj = j + coff[k];
					if(ni<0 || ni>=N || nj<0 || nj>=M) continue;
					makeEdge(currNode, node(ni, nj), 1, -val[grade[i][j]][grade[ni][nj]]);
				}
			}
		}
	}

	int result = 0;
	while(1){
		int dist[MAX_V];
		bool inQ[MAX_V] = {0};
		Edge *path[MAX_V] = {nullptr};
		queue<int> Q;
		fill(dist, dist+MAX_V, INF);
		dist[S] = 0;
		inQ[S] = true;
		Q.push(S);

		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			inQ[curr] = false;
			for(auto *e: adj[curr]){
				int next = e->to;
				if(e->spare() > 0 && dist[next] > dist[curr] + e->d){
					dist[next] = dist[curr] + e->d;
					path[next] = e;
					if(!inQ[next]){
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if(!path[E]) break;

		for(int i=E; i!=S; i=path[i]->dual->to){
			result -= path[i]->d;
			path[i]->addFlow(1);
		}
	}
	printf("%d\n", result);

	for(int i=0; i<edge.size(); i++)
		delete edge[i];
}