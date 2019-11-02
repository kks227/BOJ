#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX = MAX_N*MAX_N + 2;
const int S = MAX - 2;
const int E = MAX - 1;
const int INF = 1e9;
const int roff[2] = {-1, 0};
const int coff[2] = {0, -1};

class Dinic{
public:
	Dinic(){
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
	}

	int input(){
		int R, C, D, F, B, result = 0;
		char map[MAX_N][MAX_N];
		scanf("%d %d %d %d %d", &C, &R, &D, &F, &B);
		for(int i = 0; i < R; ++i){
			getchar();
			for(int j = 0; j < C; ++j){
				map[i][j] = getchar();
				int u = i*MAX_N + j;
				if(i == 0 || i == R-1 || j == 0 || j == C-1){
					if(map[i][j] == '.'){
						map[i][j] = '#';
						result += F;
					}
					makeEdge(S, u, INF);
				}
				else{
					if(map[i][j] == '#') makeEdge(S, u, D);
					else makeEdge(u, E, F);
				}
				for(int d = 0; d < 2; ++d){
					int nr = i+roff[d], nc = j+coff[d];
					if(nr < 0 || nc < 0) continue;
					int v = nr*MAX_N + nc;
					makeEdge(u, v, B, true);
				}
			}
		}
		return result;
	}

	int maxFlow(){
		int total = 0;
		while(bfs()){
			fill(work, work+MAX, 0);
			while(1){
				int flow = dfs(S, E, INF);
				if(flow == 0) break;
				total += flow;
			}
		}
		return total;
	}

private:
	int level[MAX], work[MAX], c[MAX][MAX], f[MAX][MAX];
	vector<int> adj[MAX];

	void makeEdge(int u, int v, int c1, bool bidir = false){
		c[u][v] = c1;
		if(bidir) c[v][u] = c1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool bfs(){
		fill(level, level+MAX, -1);
		level[S] = 0;
		queue<int> Q;
		Q.push(S);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(level[next] == -1 && c[curr][next]-f[curr][next] > 0){
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
			int next = adj[curr][i];
			if(level[next] == level[curr]+1 && c[curr][next]-f[curr][next] > 0){
				int df = dfs(next, dest, min(c[curr][next]-f[curr][next], flow));
				if(df > 0){
					f[curr][next] += df;
					f[next][curr] -= df;
					return df;
				}
			}
		}
		return 0;
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		Dinic solver;
		int temp = solver.input();
		printf("%d\n", temp + solver.maxFlow());
	}
}