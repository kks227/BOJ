#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		vector<int> adj[2500];
		scanf("%d %d", &N, &M);
		for(int i=0; i<M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u-1].push_back(v-1);
		}

		int result = 0;
		for(int i=0; i<N; i++){
			int cnt = 0;
			bool visited[2500] = {0};
			queue<int> Q;
			Q.push(i);
			visited[i] = true;
			while(!Q.empty()){
				int curr = Q.front(); Q.pop();
				cnt++;
				for(int next: adj[curr]){
					if(!visited[next]){
						visited[next] = true;
						Q.push(next);
					}
				}
			}
			result += cnt-1;
		}
		printf("%d\n", result);
	}
}