#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0 && M == 0) break;

		vector<int> adj[500];
		for(int i=0; i<M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool visited[500] = {false,};
		int prev[500], result = 0;
		fill(prev, prev+N, -1);
		for(int i=0; i<N; i++){
			if(!visited[i]){
				bool flag = true;
				queue<int> Q;
				visited[i] = true;
				Q.push(i);
				while(!Q.empty()){
					int curr = Q.front(); Q.pop();
					for(int next: adj[curr]){
						if(!visited[next]){
							visited[next] = true;
							prev[next] = curr;
							Q.push(next);
						}
						else if(next != prev[curr]) flag = false;
					}
				}
				if(flag) result++;
			}
		}
		printf("Case %d: ", t);
		if(result == 0) puts("No trees.");
		else if(result == 1) puts("There is one tree.");
		else printf("A forest of %d trees.\n", result);
	}
}