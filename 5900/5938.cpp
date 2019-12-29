#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 250;

int main(){
	int N, M;
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> Q;
	bool visited[MAX] = {true,};
	Q.push(0);
	int cnt = 0;
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
	if(cnt == N) puts("0");
	for(int i = 1; i < N; ++i)
		if(!visited[i]) printf("%d\n", i+1);
}