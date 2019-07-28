#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX = MAX_N*2 + 2;
const int S = MAX-2;
const int E = MAX-1;
const int INF = 1e9;

class Penguin{
public:
	Penguin(){
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
	}

	void input(){
		int x[MAX_N], y[MAX_N];
		double D;
		P = 0;
		scanf("%d %lf", &N, &D);
		for(int i = 0; i < N; ++i){
			int n, m, u = i*2;
			scanf("%d %d %d %d", x+i, y+i, &n, &m);
			for(int j = 0; j < i; ++j){
				int v = j*2;
				if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= D*D){
					addEdge(u+1, v, INF);
					addEdge(v+1, u, INF);
				}
			}
			if(n > 0){
				addEdge(S, u, n);
				P += n;
			}
			addEdge(u, u+1, m);
		}
	}

	void solve(){
		vector<int> result;

		for(int i = 0; i < N; ++i){
			int u = i*2, total = 0;
			addEdge(u, E, INF);

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

				int temp = INF;
				for(int i = E; i != S; i = prev[i])
					temp = min(c[prev[i]][i] - f[prev[i]][i], temp);
				total += temp;
				for(int i = E; i != S; i = prev[i]){
					f[prev[i]][i] += temp;
					f[i][prev[i]] -= temp;
				}
			}
			if(total == P) result.push_back(i);

			adj[u].pop_back();
			adj[E].pop_back();
			c[u][E] = 0;
			memset(f, 0, sizeof(f));
		}

		if(result.empty()) puts("-1");
		else{
			for(int i: result)
				printf("%d ", i);
			puts("");
		}
	}

private:
	int N, P, c[MAX][MAX], f[MAX][MAX];
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
		Penguin solver;
		solver.input();
		solver.solve();
	}
}