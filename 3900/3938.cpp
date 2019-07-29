#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 366;
const int MAX = MAX_N+2;
const int S = MAX-2;
const int E = MAX-1;
const int INF = 1e9 + 1;

struct Edge{
	int to, c, d, f;
	Edge *dual;
	Edge(): Edge(-1, 0, 0){}
	Edge(int to1, int c1, int d1): to(to1), c(c1), d(d1), f(0), dual(nullptr){}
	int spare(){ return c-f; }
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

class Concert{
public:
	Concert(){}
	~Concert(){
		for(Edge* e: edge)
			delete e;
	}

	bool input(){
		int N;
		scanf("%d", &N);
		if(N == 0) return false;

		for(int i = 0; i < N; ++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			addEdge(u-1, v, 1, -w);
		}
		for(int i = 0; i < MAX_N-1; ++i)
			addEdge(i, i+1, INF, 0);
		addEdge(S, 0, 2, 0);
		addEdge(MAX_N-1, E, 2, 0);
		return true;
	}

	int solve(){
		int total = 0, cost = 0;
		while(1){
			bool inQ[MAX] = {false,};
			Edge *prev[MAX];
			int dist[MAX];
			fill(prev, prev+MAX, nullptr);
			fill(dist, dist+MAX, INF);
			queue<int> Q;
			Q.push(S);
			inQ[S] = true;
			dist[Q.front()] = 0;

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for(Edge *e: adj[curr]){
					int next = e->to;
					if(e->spare() > 0 && dist[next] > dist[curr] + e->d){
						dist[next] = dist[curr] + e->d;
						prev[next] = e->dual;
						if(!inQ[next]){
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if(!prev[E]) break;

			int temp = INF;
			for(int i = E; i != S; i = prev[i]->to)
				temp = min(prev[i]->dual->spare(), temp);
			total += temp;
			for(int i = E; i != S; i = prev[i]->to){
				cost += -prev[i]->d * temp;
				prev[i]->addFlow(-temp);
			}
		}

		return -cost;
	}

private:
	vector<Edge*> adj[MAX];
	vector<Edge*> edge;

	void addEdge(int u, int v, int c1, int d1){
		Edge *e1 = new Edge(v, c1, d1), *e2 = new Edge(u, 0, -d1);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
		edge.push_back(e1);
		edge.push_back(e2);
	}
};

int main(){
	while(1){
		Concert solver;
		if(!solver.input()) break;
		printf("%d\n", solver.solve());
	}
}