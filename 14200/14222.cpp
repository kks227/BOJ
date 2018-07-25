#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[50], B[50];
vector<int> adj[50];
bool visited[50];

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
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		for(int j=1; j<=N; j++)
			if(val <= j && (j-val)%K == 0) adj[i].push_back(j-1);
	}

	fill(A, A+N, -1);
	fill(B, B+N, -1);
	for(int i=0; i<N; i++){
		fill(visited, visited+N, false);
		if(!dfs(i)){
			puts("0");
			return 0;
		}
	}
	puts("1");
}