#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main(){
	int N, adj[MAX][MAX];
	bool visited[MAX] = {false,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &adj[i][j]);

	vector<vector<int>> result;
	for(int i = 0; i < N; ++i){
		if(visited[i]) continue;

		queue<int> Q;
		vector<int> V;
		Q.push(i);
		visited[i] = true;
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			V.push_back(curr);
			for(int next = 0; next < N; ++next){
				if(!adj[curr][next] && !visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}

		for(int j = 0; j < V.size(); ++j){
			for(int k = j+1; k < V.size(); ++k){
				if(adj[V[j]][V[k]]){
					puts("0");
					return 0;
				}
			}
		}
		if(V.size() > 1){
			sort(V.begin(), V.end());
			result.push_back(V);
		}
	}
	sort(result.begin(), result.end());
	printf("%d\n", result.size());
	for(auto &v: result){
		for(int i: v)
			printf("%d ", i+1);
		puts("");
	}
}