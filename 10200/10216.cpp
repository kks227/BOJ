#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, x[3000], y[3000], r[3000];
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d %d %d", x+i, y+i, r+i);
		vector<int> adj[3000];
		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= (r[i]+r[j])*(r[i]+r[j])){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		bool visited[3000] = {0};
		queue<int> Q;
		int result = 0;
		for(int i=0; i<N; i++){
			if(!visited[i]){
				result++;
				visited[i] = true;
				Q.push(i);
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
			}
		}
		printf("%d\n", result);
	}
}