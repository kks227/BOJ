#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX_N = 50;
const int MAX = MAX_N*MAX_N/2;

int A[MAX], B[MAX];
bool visited[MAX];
vector<int> adj[MAX];

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
	int R, C, cnt = 0;
	char map[MAX_N][MAX_N];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == '.') ++cnt;
		}
	}
	for(int i = 0; i < R; ++i){
		for(int j = i%2; j < C; j+=2){
			if(map[i][j] == 'X') continue;
			int u = (i*MAX_N+j)/2;
			for(int d = 0; d < 4; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'X') continue;
				adj[u].push_back((nr*MAX_N+nc)/2);
			}
		}
	}

	int total = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for(int i = 0; i < MAX; ++i){
		if(A[i] == -1){
			fill(visited, visited+MAX, false);
			if(dfs(i)) ++total;
		}
	}
	printf("%d\n", cnt - total);
}