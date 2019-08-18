#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int to[MAX];
bool visited[MAX];

int dfs(int u){
	visited[u] = true;
	int v = to[u];
	if(v == -1) return 0;
	if(visited[v]) return -1;
	int temp = dfs(v);
	return temp == -1 ? -1 : temp+1;
}

int main(){
	int N, M, P;
	scanf("%d %d %d", &M, &N, &P);
	--P;
	fill(to, to+N, -1);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		if(to[v] == -1) to[v] = u;
	}
	printf("%d\n", dfs(P));
}