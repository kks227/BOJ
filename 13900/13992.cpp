#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int MAX = MAX_N + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9;
const long long INF2 = 1e18;

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

class Delight{
public:
	void input(){
		scanf("%d %d %d %d", &N, &K, &maxE, &minE);
		maxE = K - maxE;
		for(int i = 0; i < N; ++i)
			scanf("%d", s+i);
		for(int i = 0; i < N; ++i){
			scanf("%d", e+i);
			q[i] = e[i] - s[i];
		}
	}

	void solve(){
		Edge *eK[MAX_N] = {nullptr};
		for(int i = 0; i < N; ++i){
			if(i < K) addEdge(S, i, INF, 0);
			addEdge(i, (i+1 < N ? i+1 : E), maxE-minE, 0);
			eK[i] = addEdge(i, (i+K < N ? i+K : E), 1, -q[i]);
		}

		long long result = 0;
		for(int p = 0; p < maxE; ++p){
			long long dist[MAX];
			Edge* prev[MAX] = {nullptr,};
			queue<int> Q;
			bool inQ[MAX] = {false,};
			fill(dist, dist+MAX, INF2);
			dist[S] = 0;
			Q.push(S);
			inQ[S] = true;

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				inQ[curr] = false;
				for(Edge *e: adj[curr]){
					int next = e->to;
					if(e->spare() > 0 && dist[next] > dist[curr] + e->d){
						dist[next] = dist[curr] + e->d;
						prev[next] = e;
						if(!inQ[next]){
							Q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			for(int i = E; i != S; i = prev[i]->dual->to){
				result -= prev[i]->d;
				prev[i]->addFlow(1);
			}
		}

		for(int i = 0; i < N; ++i)
			result += s[i];
		printf("%lld\n", result);
		for(int i = 0; i < N; ++i)
			putchar(eK[i]->f > 0 ? 'E' : 'S');

		for(Edge *e: edge)
			delete e;
	}

private:
	int N, K, maxE, minE, s[MAX_N], e[MAX_N], q[MAX_N];
	vector<Edge*> adj[MAX];
	vector<Edge*> edge;

	Edge* addEdge(int u, int v, int c1, int d1){
		Edge *e1 = new Edge(v, c1, d1), *e2 = new Edge(u, 0, -d1);
		e1->dual = e2; e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
		return e1;
	}
};

int main(){
	Delight solver;
	solver.input();
	solver.solve();
}