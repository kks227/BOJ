#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 3000;

int main(){
	int N, M, cnt = 0, cntO = 0, deg[MAX] = {0,};
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		++deg[u]; ++deg[v];
	}
	for(int i = 0; i < N; ++i)
		if(deg[i]%2 == 1) ++cntO;
	if(cntO != 0 && cntO != 2){
		puts("NO");
		return 0;
	}

	queue<int> Q;
	bool visited[MAX] = {true,};
	Q.push(0);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		++cnt;
		for(int next: adj[curr]){
			if(!visited[next]){
				visited[next] = true;
				Q.push(next);
			}
		}
	}
	puts(cnt < N ? "NO" : "YES");
}