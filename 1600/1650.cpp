#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

struct Edge{
	int to, c, d, f;
	Edge *dual;
	Edge(): Edge(-1, -1, -1){}
	Edge(int to1, int c1, int d1): to(to1), c(c1), d(d1){
		f = 0;
		dual = nullptr;
	}
	int spare(){ return c-f; }
	int distance(){ return (f<0 ? -d : d); }
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<Edge*> edge, adj[1000];
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		Edge *e1 = new Edge(v, 1, w), *e2 = new Edge(u, 1, w);
		e1->dual = e2; e2->dual = e1;
		edge.push_back(e1); edge.push_back(e2);
		adj[u].push_back(e1); adj[v].push_back(e2);
	}

	int result = 0;
	for(int i=0; i<2; i++){
		int dist[1000];
		Edge *path[1000] = {0};
		bool inQ[1000] = {0};
		queue<int> Q;
		fill(dist, dist+N, INF);
		dist[0] = 0;
		inQ[0] = true;
		Q.push(0);

		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for(auto *e: adj[curr]){
				int next = e->to, d = e->distance();
				if(e->spare() > 0 && dist[next] > dist[curr] + d){
					dist[next] = dist[curr] + d;
					path[next] = e;
					if(!inQ[next]){
						inQ[next] = true;
						Q.push(next);
					}
				}
			}
		}
		for(int j=N-1; j!=0; j=path[j]->dual->to){
			result += path[j]->distance();
			path[j]->addFlow(1);
		}
	}
	printf("%d\n", result);
}