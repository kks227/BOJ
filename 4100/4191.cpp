#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, L;
		vector<int> adj[10000];
		scanf("%d %d %d", &N, &M, &L);
		for(int i=0; i<M; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x-1].push_back(y-1);
		}
		bool visited[10000] = {false,};
		queue<int> Q;
		for(int i=0; i<L; i++){
			int z;
			scanf("%d", &z);
			z--;
			if(!visited[z]){
				visited[z] = true;
				Q.push(z);
			}
		}
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		int result = 0;
		for(int i=0; i<N; i++)
			if(visited[i]) result++;
		printf("%d\n", result);
	}
}