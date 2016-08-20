#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[5000];
int A[5000], B[5000];
bool visited[5000];

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
	int N, AN = -1, BN = -1, Anum[100][100], Bnum[100][100];
	char map[100][100];
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			map[i][j] = getchar();
		getchar();
	}
	for(int j=0; j<N; j++){
		for(int i=0; i<N; i++){
			if(map[i][j] == 'X') continue;
			if(i == 0 || map[i-1][j] == 'X') AN++;
			Anum[i][j] = AN;
		}
	}
	AN++;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == 'X') continue;
			if(j == 0 || map[i][j-1] == 'X') BN++;
			Bnum[i][j] = BN;
		}
	}
	BN++;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(map[i][j] != 'X') adj[Anum[i][j]].push_back(Bnum[i][j]);

	fill(A, A+AN, -1);
	fill(B, B+BN, -1);
	int result = 0;
	for(int i=0; i<AN; i++){
		if(A[i] == -1){
			fill(visited, visited+AN, false);
			if(dfs(i)) result++;
		}
	}
	printf("%d\n", result);
}