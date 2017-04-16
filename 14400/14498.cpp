#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[512], B[512];
bool visited[512];
vector<int> adj[512];

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
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int n[512], m[512], c[512];
	for(int i=0; i<K; i++){
		scanf("%d %d %d", n+i, m+i, c+i);
		n[i]--; m[i]--;
		for(int j=0; j<i; j++){
			if(c[i] == c[j]) continue;
			if(n[i] == n[j] || m[i] == m[j]){
				if(c[j]) adj[i].push_back(j);
				else adj[j].push_back(i);
			}
		}
	}
	
	int result = 0;
	fill(A, A+K, -1);
	fill(B, B+K, -1);
	for(int i=0; i<K; i++){
		if(!c[i] && A[i] == -1){
			fill(visited, visited+K, false);
			if(dfs(i)) result++;
		}
	}
	printf("%d\n", result);
}