#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 20;
const int MAX = MAX_N*MAX_N*2 + 2;
const int S = MAX-2;
const int E = MAX-1;
const int INF = 1e9;

class Lizard{
public:
	Lizard(){
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
	}

	void input(){
		int R, C, D;
		scanf("%d %d\n", &R, &D);
		result = 0;
		for(int i = 0; i < R; ++i){
			for(int j = 0; ; ++j){
				char d = getchar();
				if(d == '\n'){
					if(i == 0) C = j;
					break;
				}
				int u = (i*MAX_N+j)*2;
				if(d != '0') addEdge(u, u+1, d-'0');
			}
		}
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				char d = getchar();
				int u = (i*MAX_N+j)*2;
				if(d == 'L'){
					addEdge(S, u, 1);
					++result;
				}
				for(int k = -D; k <= D; ++k){
					for(int l = -D; l <= D; ++l){
						if(abs(k)+abs(l) > D) continue;
						int v = ((i+k)*MAX_N+j+l)*2;
						if(i+k < 0 || i+k >= R || j+l < 0 || j+l >= C) v = E;
						addEdge(u+1, v, INF);
					}
				}
			}
			getchar();
		}
	}

	int solve(){
		while(1){
			bool visited[MAX] = {false,};
			int prev[MAX];
			fill(prev, prev+MAX, -1);
			queue<int> Q;
			Q.push(S);

			while(!Q.empty()){
				int curr = Q.front();
				Q.pop();
				for(int next: adj[curr]){
					if(c[curr][next]-f[curr][next] > 0 && prev[next] == -1){
						Q.push(next);
						prev[next] = curr;
					}
				}
			}
			if(prev[E] == -1) break;

			--result;
			for(int i = E; i != S; i = prev[i]){
				++f[prev[i]][i];
				--f[i][prev[i]];
			}
		}

		return result;
	}

private:
	int c[MAX][MAX], f[MAX][MAX], result;
	vector<int> adj[MAX];

	void addEdge(int u, int v, int c1){
		c[u][v] = c1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		Lizard solver;
		solver.input();
		int result = solver.solve();
		printf("Case #%d: ", t);
		if(result == 0) puts("no lizard was left behind.");
		else if(result == 1) puts("1 lizard was left behind.");
		else printf("%d lizards were left behind.\n", result);
	}
}