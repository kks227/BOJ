#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int CMAX = 1e7;
const int INF = 1e9;

struct Edge{
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1, -1){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
	int spare(){ return c-f; }
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

int main(){
	int R, C;
	while(scanf("%d %d", &R, &C) > 0){
		int S, E = 5000, ac[26];
		char map[50][50];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == '*') S = (i*50+j)*2+1;
			}
		}
		for(int i=0; i<26; i++)
			scanf("%d", ac+i);

		vector<Edge*> edge;
		vector<Edge*> adj[5001];
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(map[i][j] == '-') continue;

				int cFrom = (i*50+j)*2, cTo = cFrom+1;
				if(map[i][j] != '*'){
					Edge *e1 = new Edge(cTo, ac[map[i][j]-'A']+CMAX), *e2 = new Edge(cFrom, 0);
					e1->dual = e2; e2->dual = e1;
					adj[cFrom].push_back(e1);
					adj[cTo].push_back(e2);
				}

				for(int d=0; d<4; d++){
					int nr = i+roff[d], nc = j+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C){
						Edge *e1 = new Edge(E, INF), *e2 = new Edge(cTo, 0);
						e1->dual = e2; e2->dual = e1;
						adj[cTo].push_back(e1);
						adj[E].push_back(e2);
					}
					else if(map[nr][nc] != '-'){
						int nFrom = (nr*50+nc)*2;
						Edge *e1 = new Edge(nFrom, INF), *e2 = new Edge(cTo, 0);
						e1->dual = e2; e2->dual = e1;
						adj[cTo].push_back(e1);
						adj[nFrom].push_back(e2);
					}
				}
			}
		}

		int result = 0;
		while(1){
			bool visited[5001] = {0};
			visited[S] = true;
			Edge* path[5001];
			queue<int> Q;
			Q.push(S);

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				if(curr == E) break;

				for(Edge *e: adj[curr]){
					int next = e->to;
					if(!visited[next] && e->spare() > 0){
						visited[next] = true;
						path[next] = e;
						Q.push(next);
					}
				}
			}
			if(!visited[E]) break;

			int flow = INF;
			for(int i=E; i!=S; i=path[i]->dual->to)
				flow = min(flow, path[i]->spare());
			for(int i=E; i!=S; i=path[i]->dual->to)
				path[i]->addFlow(flow);
			result += flow;
		}
		printf("%d\n", result % CMAX);
		for(Edge* e: edge)
			delete e;
	}
}