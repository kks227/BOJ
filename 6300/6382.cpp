#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N, s, e, cnt = 0;
		scanf("%d", &N);
		if(N == 0) break;

		long long S = 0, E = 0;
		map<long long, int> node;
		map<long long, int>::iterator iter;
		vector<vector<int>> adj;
		for(int i=0; i<N; i++){
			int x;
			scanf("%d", &x);
			S = S*10 + x;
		}
		for(int i=0; i<N; i++){
			int x;
			scanf("%d", &x);
			E = E*10 + x;
		}
		while(1){
			long long U = 0, V = 0;
			int x;
			scanf("%d", &x);
			if(x == -1) break;
			U = x;
			for(int i=1; i<N; i++){
				scanf("%d", &x);
				U = U*10 + x;
			}
			for(int i=0; i<N; i++){
				scanf("%d", &x);
				V = V*10 + x;
			}

			int u, v;
			iter = node.find(U);
			if(iter == node.end()){
				u = cnt++;
				adj.push_back(vector<int>());
				node[U] = u;
			}
			else u = iter->second;
			iter = node.find(V);
			if(iter == node.end()){
				v = cnt++;
				adj.push_back(vector<int>());
				node[V] = v;
			}
			else v = iter->second;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		iter = node.find(S);
		if(iter == node.end()){
			s = cnt++;
			adj.push_back(vector<int>());
			node[S] = s;
		}
		else s = iter->second;
		iter = node.find(E);
		if(iter == node.end()){
			e = cnt++;
			adj.push_back(vector<int>());
			node[E] = e;
		}
		else e = iter->second;

		vector<bool> visited(cnt, false);
		visited[s] = true;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		printf("Maze #%d can%s be travelled\n", t, visited[e] ? "" : "not");
	}
}