#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;

vector<int> A, B, adj[144];
bool visited[144];

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

int main(){
	int R, C, N;
	char map[12][12];
	vector<int> jail, door;
	scanf("%d %d", &R, &C);
	N = R*C;
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'D') door.push_back(i*C+j);
			else if(map[i][j] == '.') jail.push_back(i*C+j);
		}
	}

	int dist[144][144];
	for(int i=0; i<N; i++)
		fill(dist[i], dist[i]+N, INF);
	for(int i: door)
		dist[i][i] = 0;
	for(int i: jail){
		dist[i][i] = 0;
		int r = i/C, c = i%C;
		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(map[nr][nc] == 'X') continue;
			dist[i][nr*C+nc] = dist[nr*C+nc][i] = 1;
		}
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	vector<int> reachable[144];
	for(int i: jail){
		bool impossible = true;
		for(int j: door){
			if(dist[i][j] < INF){
				impossible = false;
				reachable[i].push_back(j);
			}
		}
		if(impossible){
			puts("impossible");
			return 0;
		}
	}

	int match = 0;
	A.resize(N, -1);
	for(int t=1; ; t++){
		B.resize(B.size()+N, -1);
		for(int i: jail)
			for(int j: reachable[i])
				if(dist[i][j] <= t)
					adj[i].push_back(N*(t-1)+j);
		for(int i=0; i<N; i++){
			if(A[i] == -1){
				fill(visited, visited+N, false);
				if(dfs(i)) match++;
			}
		}
		if(match == jail.size()){
			printf("%d\n", t);
			return 0;
		}
	}
}