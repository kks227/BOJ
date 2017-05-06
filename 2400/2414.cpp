#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, A[2500], B[2500];
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
	int N, M, rn[50][50] = {0}, cn[50][50] = {0};
	scanf("%d %d", &N, &M);
	char map[50][50];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
	}
	for(int i=0; i<N; i++){
		int s = 0, e = 0;
		for(int j=0; j<M; j++){
			if(map[i][j] == '.'){
				if(e > s) R++;
				s = e = j+1;
			}
			else{
				rn[i][j] = R;
				e++;
			}
		}
		if(e > s) R++;
	}
	for(int j=0; j<M; j++){
		int s = 0, e = 0;
		for(int i=0; i<N; i++){
			if(map[i][j] == '.'){
				if(e > s) C++;
				s = e = j+1;
			}
			else{
				cn[i][j] = C;
				e++;
			}
		}
		if(e > s) C++;
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(map[i][j] == '*') adj[rn[i][j]].push_back(cn[i][j]);

	int result = 0;
	fill(A, A+R, -1);
	fill(B, B+C, -1);
	for(int i=0; i<R; i++){
		if(A[i] == -1){
			fill(visited, visited+R, false);
			if(dfs(i)) result++;
		}
	}
	printf("%d\n", result);
}