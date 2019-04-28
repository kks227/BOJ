#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 2000;

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
	int N, M, K = 0, L = 0;
	scanf("%d %d", &N, &M);
	unordered_map<int, int> S, C;
	bool flag[MAX] = {false,};
	for(int i = 0; i < N; ++i){
		int k;
		char c;
		scanf("%d %c", &k, &c);
		if(c == 's') S[k] = K++;
		else C[k] = L++;
	}
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		if(S.find(u) != S.end()) adj[S[u]].push_back(C[v]);
		else adj[S[v]].push_back(C[u]);
	}

	int result = N;
	fill(A, A+K, -1);
	fill(B, B+L, -1);
	for(int i = 0; i < K; ++i){
		fill(visited, visited+K, false);
		if(dfs(i)) --result;
	}
	printf("%d\n", result);
}