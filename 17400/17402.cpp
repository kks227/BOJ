#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200;

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
	int R, C, K;
	scanf("%d %d %d", &R, &C, &K);
	for(int i = 0; i < K; ++i){
		int r, c;
		scanf("%d %d", &r, &c);
		adj[r-1].push_back(c-1);
	}

	int cnt = 0;
	fill(A, A+R, -1);
	fill(B, B+C, -1);
	for(int i = 0; i < R; ++i){
		if(A[i] == -1){
			fill(visited, visited+R, false);
			if(dfs(i)) ++cnt;
		}
	}
	printf("%d\n", R+C-cnt);
}