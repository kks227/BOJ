#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_CELL = 100;
const int MAX_COOKIE = MAX_CELL/2;
const int MAX_TIME = MAX_CELL;
const int MAX_TV = MAX_CELL*2 * MAX_TIME;
const int MAX = MAX_TV + MAX_COOKIE + 2;
const int S = MAX-2;
const int E = MAX-1;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

struct Edge{
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
	int spare(){ return c-f; }
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

class Cookie{
public:
	~Cookie(){ for(Edge* e: edge) delete e; }

	void input(){
		scanf("%d %d %d", &R, &C, &N);
		fill(isWeak, isWeak + R*C, false);
		for(int i = 0; i < N; ++i){
			int r, c;
			scanf("%d %d", &r, &c);
			sPos[i] = (r-1)*C + c-1;
		}
		for(int i = 0; i < N; ++i){
			int r, c;
			scanf("%d %d", &r, &c);
			ePos[i] = (r-1)*C + c-1;
			isWeak[(r-1)*C + c-1] = true;
		}
	}

	int solve(){
		for(int i = 0; i < N; ++i){
			addEdge(S, sPos[i]*2+1, 1);
			addEdge(MAX_TV + i, E, 1);
		}
		for(int i = 0; i < MAX_TIME; ++i){
			for(int j = 0; j < MAX_CELL; ++j){
				int u = MAX_CELL*2*i + j*2, v = u + 1;
				if(i > 0) addEdge(v - MAX_CELL*2, u, INF);
				addEdge(u, v, 1);
				if(isWeak[j] || i == MAX_TIME-1) continue;

				int r = j/C, c = j%C;
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
					int w = MAX_CELL*2*(i+1) + (nr*C + nc)*2;
					addEdge(v, w, INF);
				}
			}
		}

		int total = 0;
		for(int i = 0; i < MAX_TIME; ++i){
			for(int j = 0; j < N; ++j)
				addEdge(MAX_CELL*2*i + ePos[j]*2 + 1, MAX_TV + j, INF);

			while(1){
				queue<int> Q;
				Edge *prev[MAX] = {nullptr,};
				Q.push(S);
				while(!Q.empty()){
					int curr = Q.front(); Q.pop();
					for(Edge *e: adj[curr]){
						int next = e->to;
						if(e->spare() > 0 && !prev[next]){
							prev[next] = e->dual;
							Q.push(next);
						}
					}
				}
				if(!prev[E]) break;

				++total;
				for(int i = E; i != S; i = prev[i]->to)
					prev[i]->dual->addFlow(1);
			}

			if(total == N) return i;
		}
		return -1;
	}

private:
	int R, C, N, sPos[MAX_COOKIE], ePos[MAX_COOKIE];
	bool isWeak[MAX_CELL];
	vector<Edge*> adj[MAX], edge;

	void addEdge(int u, int v, int c){
		Edge *e1 = new Edge(v, c), *e2 = new Edge(u, 0);
		e1->dual = e2; e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
		edge.push_back(e1);
		edge.push_back(e2);
	}
};



int main(){
	Cookie solver;
	solver.input();
	printf("%d\n", solver.solve());
}