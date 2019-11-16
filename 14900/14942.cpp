#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int MAX = 100000;
const int MAX_D = 18;
typedef pair<int, int> P;

int main(){
	int N, A[MAX], p[MAX][MAX_D], d[MAX][MAX_D] = {0,};
	vector<P> adj[MAX];
	memset(p, -1, sizeof(p));
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	for(int i = 0; i < N-1; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		adj[u].push_back(P(v, w));
		adj[v].push_back(P(u, w));
	}

	queue<int> Q;
	bool visited[MAX] = {true,};
	Q.push(0);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(auto &e: adj[curr]){
			int next = e.first;
			if(!visited[next]){
				visited[next] = true;
				p[next][0] = curr;
				d[next][0] = e.second;
				Q.push(next);
			}
		}
	}
	for(int j = 1; j < MAX_D; ++j){
		for(int i = 0; i < N; ++i){
			if(p[i][j-1] != -1){
				p[i][j] = p[ p[i][j-1] ][j-1];
				d[i][j] = d[i][j-1] + d[ p[i][j-1] ][j-1];
			}
			else d[i][j] = d[i][j-1];
		}
	}

	for(int i = 0; i < N; ++i){
		int u = i, k = A[i];
		for(int j = MAX_D-1; j >= 0 && u != -1; --j){
			if(k >= d[u][j]){
				k -= d[u][j];
				u = p[u][j];
			}
		}
		if(u == -1) u = 0;
		printf("%d\n", u+1);
	}
}