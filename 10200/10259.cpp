#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 200000;

int main(){
	int N, M, color[MAX], result = 0;
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	fill(color, color+N, -1);
	bool impossible = false;
	for(int i = 0; i < M; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		if(w == 1){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		else{
			int c = w/2;
			if(color[u] == !c || color[v] == !c) impossible = true;
			else color[u] = color[v] = c;
		}
	}
	if(impossible){
		puts("impossible");
		return 0;
	}

	bool visited[MAX] = {false,};
	for(int i = 0; i < N; ++i){
		if(color[i] == -1 || visited[i]) continue;

		queue<int> Q;
		Q.push(i);
		visited[i] = true;
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			if(color[curr] == 1) ++result;
			for(int next: adj[curr]){
				if(color[curr] == color[next]){
					puts("impossible");
					return 0;
				}
				if(color[next] == -1){
					color[next] = !color[curr];
					Q.push(next);
					visited[next] = true;
				}
			}
		}
	}

	for(int i = 0; i < N; ++i){
		if(color[i] != -1) continue;

		queue<int> Q;
		Q.push(i);
		color[i] = 1;
		int cnt1 = 0, cnt2 = 0;
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			if(color[curr] == 1) ++cnt1;
			++cnt2;
			for(int next: adj[curr]){
				if(color[curr] == color[next]){
					puts("impossible");
					return 0;
				}
				if(color[next] == -1){
					color[next] = !color[curr];
					Q.push(next);
				}
			}
		}
		result += min(cnt1, cnt2-cnt1);
	}
	printf("%d\n", result);
}