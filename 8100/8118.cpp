#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX = MAX_N * MAX_N;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

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
	int N;
	scanf("%d", &N);
	bool map[MAX_N][MAX_N] = {false,};
	for(int i = 0; i < 3; ++i){
		int k;
		scanf("%d", &k);
		--k;
		map[k/N][k%N] = true;
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if((i+j)%2 != 0 || map[i][j]) continue;
			for(int d = 0; d < 4; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr >= 0 && nr < N && nc >= 0 && nc < N && !map[nr][nc])
					adj[i*N+j].push_back(nr*N+nc);
			}
		}
	}

	fill(A, A+N*N, -1);
	fill(B, B+N*N, -1);
	int total = 0;
	for(int i = 0; i < N*N; i += 2){
		if(!map[i/N][i%N] && A[i] == -1){
			fill(visited, visited+N*N, false);
			if(dfs(i)) ++total;
		}
	}
	if(total < (N*N-3)/2){
		puts("NIE");
		return 0;
	}
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if((i+j)%2 == 0 && !map[i][j]) printf("%d %d\n", i*N+j+1, A[i*N+j]+1);
}