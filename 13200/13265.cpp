#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int V, E;
		scanf("%d %d", &V, &E);
		vector<int> adj[1000];
		for(int i=0; i<E; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int group[1000];
		fill(group, group+V, -1);
		for(int i=0; i<V; i++){
			if(group[i] != -1) continue;
			bool flag = false;
			group[i] = 1;
			queue<int> Q;
			Q.push(i);
			while(!Q.empty()){
				int qSize = Q.size();
				for(int i=0; i<qSize; i++){
					int curr = Q.front();
					Q.pop();
					for(int next: adj[curr])
						if(group[next] == -1){
							Q.push(next);
							group[next] = flag;
						}
				}
				flag = !flag;
			}
		}

		bool result = true;
		for(int i=0; i<V; i++){
			for(int j: adj[i])
				if(group[i] == group[j]){
					result = false;
					break;
				}
			if(!result) break;
		}
		puts(result ? "possible" : "impossible");
	}
}