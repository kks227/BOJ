#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;
const int MAX_C = 4; // 색은 4개면 충분하다. 그래프 이론이 그렇다고 하더라

int N, dp[MAX_N][MAX_C+1];
vector<int> adj[MAX_N], child[MAX_N];
bool visited[MAX_N];

void dfs(int curr){
	visited[curr] = true;
	for(int next: adj[curr]){
		if(!visited[next]){
			child[curr].push_back(next);
			dfs(next);
		}
	}
}

int paint(int root, int pc){
	int &ret = dp[root][pc];
	if(ret != -1) return ret;

	ret = 1000000000;
	for(int c=1; c<=MAX_C; c++){
		if(c == pc) continue;
		int temp = c;
		for(int next: child[root])
			temp += paint(next, c);
		ret = min(ret, temp);
	}
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		adj[A-1].push_back(B-1);
		adj[B-1].push_back(A-1);
	}
	dfs(0);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", paint(0, 0));
}