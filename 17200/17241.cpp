#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 200000;

int main(){
	int N, M, Q;
	vector<int> adj[MAX];
	scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool visited[MAX] = {false,}, used[MAX] = {false,};
	for(int i = 0; i < Q; ++i){
		int u, cnt = 0;
		scanf("%d", &u);
		--u;
		if(used[u]){
			puts("0");
			continue;
		}
		used[u] = true;
		if(!visited[u]){
			visited[u] = true;
			++cnt;
		}
		for(int v: adj[u]){
			if(!visited[v]){
				visited[v] = true;
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
}