#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int S, E, N, M;
	scanf("%d %d %d %d", &S, &E, &N, &M);
	S--; E--;
	vector<int> adj[1000];
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}

	bool visited[1000] = {0};
	visited[S] = true;
	queue<int> Q;
	Q.push(S);
	for(int result = 0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int curr = Q.front();
			Q.pop();
			if(curr == E){
				printf("%d\n", result);
				return 0;
			}
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
	puts("-1");
}