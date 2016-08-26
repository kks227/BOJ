#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

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
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i=0; i<MAX; i++)
			adj[i].clear();
		for(int i=0; i<M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		int result = 0;
		fill(A, A+MAX, -1);
		fill(B, B+MAX, -1);
		for(int i=0; i<N; i++){
			if(A[i] == -1){
				fill(visited, visited+MAX, false);
				if(dfs(i)) result++;
			}
		}
		printf("%d\n", result);
	}
}