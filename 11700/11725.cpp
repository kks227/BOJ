#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> adj[100000];
int parent[100000];

void DFS(int cur){
	for(int next: adj[cur])
		if(parent[next] == -1){
			parent[next] = cur;
			DFS(next);
		}
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	memset(parent, -1, sizeof(parent));
	DFS(0);
	for(int i=1; i<N; i++)
		printf("%d\n", parent[i]+1);
}