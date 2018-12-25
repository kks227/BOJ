#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_V = MAX_N*(MAX_N+3) + 4;
const int S0 = MAX_V-4;
const int E0 = MAX_V-3;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1e9;
typedef tuple<int, int, int> IntTuple;

class Edge{
public:
	int to, c, lb, f0, f;
	Edge *dual;
	Edge(): Edge(0, 0, 0){}
	Edge(int to1, int c1, int lb1): to(to1), c(c1), lb(lb1), f0(0), f(0), dual(nullptr){}
	int spare(){ return c-f; }
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

class Dinic{
public:
	~Dinic(){
		for(Edge* e: edge)
			delete e;
	}

	void input(){
		int p1, p2, q1[MAX_N], q2[MAX_N];
		vector<IntTuple> r[MAX_N];
		scanf("%d %d %d %d", &M, &N, &p1, &p2);
		for(int i = 0; i < N; ++i)
			scanf("%d %d", q1+i, q2+i);
		for(int i = 0; i < M; ++i){
			int k;
			scanf("%d", &k);
			for(int j = 0; j < k; ++j){
				int d, r1, r2;
				scanf("%d %d %d", &d, &r1, &r2);
				r[i].push_back(IntTuple(d, r1, r2));
			}
		}

		for(int i = 0; i < M; ++i){
			int u = MAX_N*MAX_N + i, v, w, rSize = 0;
			makeEdge(S0, u, p2, p1);
			bool check[MAX_N] = {false,};
			for(int k = 0; k < r[i].size(); ++k){
				int d, r1, r2;
				tie(d, r1, r2) = r[i][k];
				v = MAX_N*i + k;
				makeEdge(u, v, r2-r1+1 - d);
				for(int j = r1-1; j < r2; ++j){
					w = MAX_N*(MAX_N+2) + j;
					man2day[i][j] = makeEdge(v, w, 1);
					check[j] = true;
				}
				rSize += r2-r1+1;
			}
			v = MAX_N*(MAX_N+1) + i;
			makeEdge(u, v, N-rSize, N-rSize);
			for(int j = 0; j < N; ++j){
				if(!check[j]){
					w = MAX_N*(MAX_N+2) + j;
					makeEdge(v, w, 1);
					man2day[i][j] = nullptr;
				}
			}
		}
		for(int i = 0; i < N; ++i){
			int u = MAX_N*(MAX_N+2) + i;
			makeEdge(u, E0, q2[i], q1[i]);
		}
		makeEdge(E0, S0, INF);

		int demand[MAX_V-2] = {0};
		D = 0;
		for(Edge* e: edge){
			int &lb = e->lb;
			if(lb > 0){
				demand[e->to] -= lb;
				demand[e->dual->to] += lb;
				e->c -= lb;
				e->f0 = lb;
				lb = 0;
			}
		}
		for(int i = 0; i < MAX_V-2; ++i){
			if(demand[i] < 0)
				makeEdge(S, i, -demand[i]);
			else if(demand[i] > 0){
				makeEdge(i, E, demand[i]);
				D += demand[i];
			}
		}
	}

	int solve(){
		int total = 0;
		while(bfs()){
			fill(work, work+MAX_V, 0);
			while(1){
				int flow = dfs(S, E, INF);
				if(flow == 0) break;
				total += flow;
			}
		}

		if(total < D) puts("-1");
		else{
			puts("1");
			for(int i = 0; i < M; ++i){
				vector<int> result;
				for(int j = 0; j < N; ++j)
					if(man2day[i][j] && man2day[i][j]->f + man2day[i][j]->f0 == 0) result.push_back(j+1);
				printf("%d", result.size());
				for(int j: result)
					printf(" %d", j);
				puts("");
			}
		}

		return total;
	}

private:
	int N, M, D, level[MAX_V], work[MAX_V];
	vector<Edge*> edge;
	vector<Edge*> adj[MAX_V];
	Edge* man2day[MAX_N][MAX_N];

	Edge* makeEdge(int u, int v, int c, int lb = 0){
		Edge *e1 = new Edge(v, c, lb);
		Edge *e2 = new Edge(u, 0, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
		edge.push_back(e1);
		edge.push_back(e2);
		return e1;
	}

	bool bfs(){
		fill(level, level+MAX_V, -1);
		level[S] = 0;

		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(Edge* e: adj[curr]){
				int next = e->to;
				if(level[next] == -1 && e->spare() > 0){
					level[next] = level[curr] + 1;
					Q.push(next);
				}
			}
		}
		return level[E] != -1;
	}

	int dfs(int curr, int dest, int flow){
		if(curr == dest) return flow;

		for(int &i = work[curr]; i < adj[curr].size(); ++i){
			Edge *e = adj[curr][i];
			int next = e->to;
			if(level[next] == level[curr]+1 && e->spare() > 0){
				int df = dfs(next, dest, min(e->spare(), flow));
				if(df > 0){
					e->addFlow(df);
					return df;
				}
			}
		}
		return 0;
	}
};



int main(){
	Dinic G;
	G.input();
	G.solve();
}