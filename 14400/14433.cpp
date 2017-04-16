#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[300], B[300];
bool visited[300];
vector<int> adj[300];

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
	int N, M, K[2], result[2] = {0};
	scanf("%d %d %d %d", &N, &M, K, K+1);
	for(int k=0; k<2; k++){
		for(int i=0; i<K[k]; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u-1].push_back(v-1);
		}
		fill(A, A+N, -1);
		fill(B, B+M, -1);
		for(int i=0; i<N; i++){
			if(A[i] == -1){
				fill(visited, visited+N, false);
				if(dfs(i)) result[k]++;
			}
		}
		for(int i=0; i<N; i++)
			adj[i].clear();
	}
	puts(result[0] < result[1] ? "네 다음 힐딱이" : "그만 알아보자");
}