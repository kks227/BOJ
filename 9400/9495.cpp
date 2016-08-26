#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int A[2500], B[2500];
vector<int> adj[2500];
bool visited[2500];

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
	int N, result = 0;
	scanf("%d\n", &N);
	char map[50][50];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			map[i][j] = getchar();
			if(map[i][j] != 'x') result++;
		}
		getchar();
	}
	vector<int> V;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 'o'){
				V.push_back(i*N+j);
				for(int d=0; d<4; d++){
					int ni = i + roff[d];
					int nj = j + coff[d];
					if(ni<0 || ni>=N || nj<0 || nj>=N) continue;
					if(map[ni][nj] == '.') adj[i*N+j].push_back(ni*N+nj);
				}
			}
		}
	}

	fill(A, A+2500, -1);
	fill(B, B+2500, -1);
	for(int i: V){
		if(A[i] == -1){
			fill(visited, visited+2500, false);
			if(dfs(i)) result--;
		}
	}
	printf("%d\n", result);
}