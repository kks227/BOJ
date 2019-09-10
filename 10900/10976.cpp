#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200;
const int INF = 1e9;

class Refuge{
public:
	int solve(){
		int result = 0;
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; ++i){
			fill(d[i], d[i]+N, INF);
			d[i][i] = 0;
		}
		X = Y = 0;
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			d[--u][--v] = 1;
			if(u == 0 && v == N-1) ++result;
			else if(u == 0) x[X++] = v;
			else if(v == N-1) y[Y++] = u;
		}

		for(int k = 0; k < N; ++k)
			for(int i = 0; i < N; ++i)
				for(int j = 0; j < N; ++j)
					d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
		for(int i = 0; i < X; ++i)
			for(int j = 0; j < Y; ++j)
				if(d[x[i]][y[j]] < INF) adj[i].push_back(j);

		fill(A, A+X, -1);
		fill(B, B+Y, -1);
		for(int i = 0; i < X; ++i){
			if(A[i] == -1){
				fill(visited, visited+X, false);
				if(dfs(i)) ++result;
			}
		}
		return result;
	}

private:
	int N, M, d[MAX][MAX], X, Y, x[MAX], y[MAX], A[MAX], B[MAX];
	vector<int> adj[MAX];
	bool visited[MAX];

	bool dfs(int a){
		visited[a] = true;
		for(int b: adj[a]){
			if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
				A[a] = b;
				B[b] = a;
				return true;
			}
		}
		return false;
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		Refuge solver;
		printf("%d\n", solver.solve());
	}
}