#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 11;
const int MAX_V = MAX_N*MAX_N+2;
const int S = MAX_V-2;
const int E = MAX_V-1;
const int INF = 1000000000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int val[6][6] = {
	{100, 70, 40,},
	{70, 50, 30,},
	{40, 30, 20,},
};

inline int nodeNum(int r, int c){ return r*MAX_N+c; }

int main(){
	int N, grade[MAX_N][MAX_N];
	int c[MAX_V][MAX_V] = {0}, d[MAX_V][MAX_V] = {0}, f[MAX_V][MAX_V] = {0};
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			grade[i][j] = getchar() - 'A';
		getchar();
	}

	vector<int> adj[MAX_V];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int curr = nodeNum(i, j);

			if(i%2 == j%2){
				c[S][curr] = 1;
				adj[S].push_back(curr);
				adj[curr].push_back(S);

				for(int k=0; k<4; k++){
					int ni = i + roff[k];
					int nj = j + coff[k];
					if(ni<0 || ni>=N || nj<0 || nj>=N) continue;

					int next = nodeNum(ni, nj);
					c[curr][next] = 1;
					d[curr][next] = -val[grade[i][j]][grade[ni][nj]];
					d[next][curr] = val[grade[i][j]][grade[ni][nj]];
					adj[curr].push_back(next);
					adj[next].push_back(curr);
				}
			}
			c[curr][E] = 1;
			adj[curr].push_back(E);
			adj[E].push_back(curr);
		}
	}

	int result = 0;
	while(1){
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = {0};
		queue<int> Q;
		fill(prev, prev+MAX_V, -1);
		fill(dist, dist+MAX_V, INF);
		dist[S] = 0;
		inQ[S] = true;
		Q.push(S);

		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;
			for(int next: adj[curr]){
				if(c[curr][next]-f[curr][next] > 0 && dist[next] > dist[curr]+d[curr][next]){
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if(!inQ[next]){
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if(prev[E] == -1) break;

		for(int i=E; i!=S; i=prev[i]){
			result -= d[prev[i]][i];
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
	}
	printf("%d\n", result);
}