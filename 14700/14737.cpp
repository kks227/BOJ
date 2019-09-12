#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX = MAX_N*MAX_N*2;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};

class Graph{
public:
	Graph(): Graph(0){}
	Graph(int V1): V(V1){}
	void addEdge(int u, int v){ adj[u].push_back(v); }
	void addClause(int p, int q){
		adj[oppo(p)].push_back(q);
		adj[oppo(q)].push_back(p);
	}
	int getSCCNum(int v){ return sccNum[v]; }

	int getSCCs(){
		dcnt = SN = 0;
		fill(dfsn, dfsn + V, -1);
		fill(finished, finished + V, false);
		for(int i = 0; i < V; ++i)
			if(dfsn[i] == -1) dfs(i);
		return SN;
	}

	void constructSCCDAG(Graph &G){
		G.V = SN;
		for(int i = 0; i < V; ++i){
			int u = sccNum[i];
			for(int j: adj[i]){
				int v = sccNum[j];
				if(u != v) G.adj[u].push_back(v);
			}
		}
		for(int i = 0; i < G.V; ++i){
			auto &a = G.adj[i];
			sort(a.begin(), a.end());
			a.resize(unique(a.begin(), a.end()) - a.begin());
		}
	}

	void getReachables(int s, vector<bool> &visited){
		queue<int> Q;
		visited[s] = true;
		Q.push(s);
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}

	bool solve2SAT(){
		getSCCs();
		for(int i = 0; i < V/2; ++i)
			if(sccNum[i*2] == sccNum[i*2+1]) return false;
		return true;
	}

private:
	int V, dcnt, dfsn[MAX], SN, sccNum[MAX];
	vector<int> adj[MAX];
	stack<int> S;
	bool finished[MAX];

	inline int oppo(int p){ return p/2*2 + !(p%2); }

	int dfs(int curr){
		int ret = dfsn[curr] = dcnt++;
		S.push(curr);
		for(int next: adj[curr]){
			if(dfsn[next] == -1) ret = min(dfs(next), ret);
			else if(!finished[next]) ret = min(dfsn[next], ret);
		}
		if(ret == dfsn[curr]){
			while(1){
				int v = S.top(); S.pop();
				sccNum[v] = SN;
				finished[v] = true;
				if(v == curr) break;
			}
			++SN;
		}
		return ret;
	}
};

class Dev{
public:
	void input(){
		scanf("%d %d", &R, &C);
		cellCnt = 0;
		for(int i = 0; i < R; ++i){
			getchar();
			for(int j = 0; j < C; ++j){
				map[i][j] = getchar();
				if(map[i][j] != '#') cellNum[i][j] = cellCnt++;
				if(map[i][j] == 'O'){ sr = i; sc = j; }
				else if(map[i][j] == '*')
					starPos.push_back(cellNum[i][j]);
			}
		}
	}

	bool solve(){
		Graph G(cellCnt);
		int to[MAX/2][2];
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				if(map[i][j] == '#') continue;
				int u = cellNum[i][j];
				for(int d = 0; d < 4; ++d){
					int nr = i, nc = j;
					while(1){
						nr += roff[d]; nc += coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#'){
							nr -= roff[d]; nc -= coff[d];
							break;
						}
					}
					int v = cellNum[nr][nc];
					G.addEdge(u, v);
					to[u][d%2] = v;
				}
			}
		}
		int SN = G.getSCCs();

		Graph SG;
		G.constructSCCDAG(SG);

		Graph H(SN*2); // 2-SAT
		int ss = G.getSCCNum(cellNum[sr][sc]);
		H.addClause(ss*2+1, ss*2+1);
		vector<bool> reachable[MAX/2];
		for(int i = 0; i < SN; ++i){
			reachable[i].resize(SN, false);
			SG.getReachables(i, reachable[i]);
		}
		for(int i = 0; i < SN; ++i)
			if(!reachable[ss][i]) H.addClause(i*2, i*2);
		for(int i = 0; i < SN; ++i){
			if(!reachable[ss][i]) continue;
			for(int j = 0; j < SN; ++j){
				if(!reachable[ss][j]) continue;
				if(!reachable[i][j] && !reachable[j][i]) H.addClause(i*2, j*2);
			}
		}
		for(int i: starPos)
			H.addClause(G.getSCCNum(to[i][0])*2+1, G.getSCCNum(to[i][1])*2+1);
		return H.solve2SAT();
	}

private:
	int R, C, sr, sc, cellNum[MAX_N][MAX_N], cellCnt;
	char map[MAX_N][MAX_N];
	vector<int> starPos;
};

int main(){
	Dev solver;
	solver.input();
	puts(solver.solve() ? "YES" : "NO");
}