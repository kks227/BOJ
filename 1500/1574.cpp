#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[300];
int A[300], B[300];
bool visited[300];

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
	bool map[300][300] = {0};
	scanf("%d %d %d", &R, &C, &N);
	for(int i=0; i<N; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = true;
	}
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(!map[i][j]) adj[i].push_back(j);

	fill(A, A+R, -1);
	fill(B, B+C, -1);
	int result = 0;
	for(int i=0; i<R; i++){
		if(A[i] == -1){
			fill(visited, visited+R, false);
			if(dfs(i)) result++;
		}
	}
	printf("%d\n", result);
}