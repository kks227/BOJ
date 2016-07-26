#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool visited[99];
int cnt, N, M;
vector<int> pre[99], suc[99];

void DFS(int cur, vector<int> *adj){
	if(visited[cur]) return;
	visited[cur] = true;
	cnt++;
	for(int next: adj[cur]) DFS(next, adj);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int p, q;
		scanf("%d %d", &p, &q);
		p--; q--;
		pre[p].push_back(q);
		suc[q].push_back(p);
	}
	int result = 0;
	for(int i=0; i<N; i++){
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		DFS(i, pre);
		if(cnt > N/2+1){
			result++;
			continue;
		}
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		DFS(i, suc);
		if(cnt > N/2+1) result++;
	}
	printf("%d\n", result);
}