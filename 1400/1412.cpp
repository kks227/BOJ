#include <cstdio>
#include <algorithm>
using namespace std;

int N;
bool adj[100][100], visited[100], finished[100], result;

void dfs(int curr, int prev){
	visited[curr] = true;
	for(int i=0; i<N; i++){
		if(i == curr || i == prev || !adj[curr][i] || adj[i][curr]) continue;
		if(!visited[i]) dfs(i, curr);
		else if(!finished[i]) result = true;
	}
	finished[curr] = true;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			adj[i][j] = (getchar() == 'Y');
	}
	for(int i=0; i<N; i++)
		if(!visited[i]) dfs(i, -1);
	puts(result ? "NO" : "YES");
}